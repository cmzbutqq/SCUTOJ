import numpy as np
import matplotlib.pyplot as plt

class KMeansCustom:
    def __init__(self, n_clusters=2, max_iter=300, tol=1e-4, random_state=None):
        self.n_clusters = n_clusters
        self.max_iter = max_iter
        self.tol = tol
        self.random_state = random_state

    def fit(self, X):
        np.random.seed(self.random_state)
        # 随机初始化簇中心
        indices = np.random.choice(len(X), self.n_clusters, replace=False)
        self.centroids = X[indices]

        for _ in range(self.max_iter):
            # 计算所有样本到每个质心的距离并分配标签
            distances = np.linalg.norm(X[:, np.newaxis] - self.centroids, axis=2)
            labels = np.argmin(distances, axis=1)

            # 重新计算质心
            new_centroids = np.array([X[labels == k].mean(axis=0) for k in range(self.n_clusters)])

            # 如果质心变化小于阈值则停止
            if np.linalg.norm(self.centroids - new_centroids) < self.tol:
                break

            self.centroids = new_centroids

        self.labels_ = labels
        return self

    def predict(self, X):
        distances = np.linalg.norm(X[:, np.newaxis] - self.centroids, axis=2)
        return np.argmin(distances, axis=1)

import numpy as np

class DBSCANCustom:
    def __init__(self, eps=0.2, min_samples=5, n_clusters=None, auto_eps_tune=False, eps_range=(0.05, 1.0), max_search_iter=20):
        self.eps = eps
        self.min_samples = min_samples
        self.n_clusters = n_clusters
        self.auto_eps_tune = auto_eps_tune
        self.eps_range = eps_range
        self.max_search_iter = max_search_iter

    def fit(self, X):
        if self.auto_eps_tune and self.n_clusters is not None:
            self.eps = self._tune_eps(X)
            print(f"[自动调整] 选定 eps = {self.eps:.3f}")

        self.labels_ = np.full(len(X), -1)
        cluster_id = 0
        visited = np.zeros(len(X), dtype=bool)

        for i in range(len(X)):
            if visited[i]:
                continue
            visited[i] = True
            neighbors = self.region_query(X, i)

            if len(neighbors) < self.min_samples:
                self.labels_[i] = -1
            else:
                self.expand_cluster(X, i, neighbors, cluster_id, visited)
                cluster_id += 1

        self.actual_clusters_ = len(set(self.labels_)) - (1 if -1 in self.labels_ else 0)
        return self

    def region_query(self, X, point_idx):
        dists = np.linalg.norm(X - X[point_idx], axis=1)
        return np.where(dists <= self.eps)[0]

    def expand_cluster(self, X, point_idx, neighbors, cluster_id, visited):
        self.labels_[point_idx] = cluster_id
        i = 0
        while i < len(neighbors):
            idx = neighbors[i]
            if not visited[idx]:
                visited[idx] = True
                new_neighbors = self.region_query(X, idx)
                if len(new_neighbors) >= self.min_samples:
                    neighbors = np.concatenate((neighbors, new_neighbors))
            if self.labels_[idx] == -1:
                self.labels_[idx] = cluster_id
            i += 1

def _tune_eps(self, X):
    """通过二分搜索找到能产生目标聚类数的 eps"""
    low, high = self.eps_range
    best_eps = self.eps
    best_diff = float('inf')

    for _ in range(self.max_search_iter):
        mid = (low + high) / 2
        temp = DBSCANCustom(eps=mid, min_samples=self.min_samples)
        temp.fit(X)
        n_clusters_found = temp.actual_clusters_
        diff = abs(n_clusters_found - self.n_clusters)

        if diff < best_diff:
            best_diff = diff
            best_eps = mid

        if n_clusters_found < self.n_clusters:
            high = mid
        else:
            low = mid

        if best_diff == 0:
            break

    return best_eps

from sklearn.datasets import make_moons

# 生成数据
X, y = make_moons(n_samples=1000, shuffle=True, noise=0.1, random_state=10)

plt.figure(figsize=(15, 4))
plt.subplot(1, 3, 1)
plt.scatter(X[:, 0], X[:, 1], c=y, cmap='viridis', s=10)
plt.title("Original Data")

kmeans = KMeansCustom(n_clusters=2, random_state=42)
kmeans.fit(X)
plt.subplot(1, 3, 2)
plt.scatter(X[:, 0], X[:, 1], c=kmeans.labels_, cmap='viridis', s=10)
plt.title("KMeans")

dbscan = DBSCANCustom(min_samples=5, n_clusters=2, auto_eps_tune=True)
dbscan.fit(X)
plt.subplot(1, 3, 3)
plt.scatter(X[:, 0], X[:, 1], c=dbscan.labels_, cmap='rainbow', s=10)
plt.title("DBSCAN")

plt.tight_layout()
plt.show()

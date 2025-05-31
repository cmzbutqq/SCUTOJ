#include <algorithm> // for std::merge
#include <iostream>
#include <vector>

// 选手结构体
struct Player {
    int strength; // 战力值
    int score;    // 当前分数
};

// 自定义比较函数
bool comparePlayers(const Player &a, const Player &b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.strength < b.strength;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, c, ftyyyds_rank;
    std::cin >> n >> c >> ftyyyds_rank;

    int total_players = 2 * n;

    // 主存储，交替使用
    std::vector<Player> players_A(total_players);
    std::vector<Player> players_B(total_players);

    // 读取战力值到 players_A
    for (int i = 0; i < total_players; ++i) {
        std::cin >> players_A[i].strength;
    }

    // 读取初始分数到 players_A
    for (int i = 0; i < total_players; ++i) {
        std::cin >> players_A[i].score;
    }

    // current_players 指向当前活动的 vector，next_players 指向用于下一轮写入的
    // vector
    std::vector<Player> *current_players_ptr = &players_A;
    std::vector<Player> *next_players_ptr = &players_B;

    // 存储胜者和败者，每轮清空并重新填充
    std::vector<Player> winners;
    winners.reserve(n); // 预留空间，避免频繁扩容
    std::vector<Player> losers;
    losers.reserve(n); // 预留空间

    // 模拟C轮比赛
    for (int round = 0; round < c; ++round) {
        winners.clear(); // 清空上一轮的数据
        losers.clear();  // 清空上一轮的数据

        // 分组比赛
        for (int i = 0; i < total_players; i += 2) {
            Player p1 = (*current_players_ptr)
                [i]; // 取出，这里如果是引用可能分数修改有问题，所以用值拷贝
            Player p2 = (*current_players_ptr)[i + 1];

            if (p1.strength > p2.strength) {
                p1.score++;
                winners.push_back(p1);
                losers.push_back(p2);
            } else {
                p2.score++;
                winners.push_back(p2);
                losers.push_back(p1);
            }
        }

        // 归并胜者和败者列表，写入 next_players_ptr 指向的 vector
        // std::merge 的输入要求是有序的，这里的 winners 和 losers
        // 分别是从一个有序列表中按顺序取出并修改分数的，所以其内部相对顺序仍保持。
        // 但需要注意，如果 Player 是引用，修改 score 会影响到原 players_A
        // 的数据。 这里的 p1, p2 是值拷贝，确保了 winners 和 losers
        // 内部是独立的、带有新分数的 Player 对象。
        std::merge(winners.begin(), winners.end(), losers.begin(), losers.end(),
                   next_players_ptr->begin(), // 输出到 next_players_ptr
                   comparePlayers);

        // 交换指针，使得下一轮从 next_players_ptr 读取，写入
        // current_players_ptr
        std::swap(current_players_ptr, next_players_ptr);
    }

    // 输出ftyyyds_rank对应的选手分数
    // 注意ftyyyds_rank是1-indexed，所以需要减1
    std::cout << (*current_players_ptr)[ftyyyds_rank - 1].score << std::endl;

    return 0;
}
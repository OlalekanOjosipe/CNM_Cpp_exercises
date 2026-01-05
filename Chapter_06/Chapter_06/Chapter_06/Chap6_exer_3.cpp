#include <iostream>
#include <random>
using namespace std;

int main() {
    long long N;
    cout << "Number of simulated games: ";
    cin >> N;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distDoor(0, 2); // doors 0,1,2

    long long wins_stick = 0;
    long long wins_switch = 0;

    for (long long i = 0; i < N; ++i) {
        int car_door = distDoor(gen);     // where the car is
        int player_choice = distDoor(gen); // initial choice

        // Host opens a door with a goat (not player's, not car's)
        int host_door;
        for (;;) {
            host_door = distDoor(gen);
            if (host_door != player_choice && host_door != car_door)
                break;
        }

        // Strategy 1: stick with original choice
        int final_stick = player_choice;

        // Strategy 2: switch to the other unopened door
        int final_switch;
        for (int d = 0; d < 3; ++d) {
            if (d != player_choice && d != host_door) {
                final_switch = d;
                break;
            }
        }

        if (final_stick == car_door)  wins_stick++;
        if (final_switch == car_door) wins_switch++;
    }

    double p_stick  = static_cast<double>(wins_stick)  / N;
    double p_switch = static_cast<double>(wins_switch) / N;

    cout << "Probability of winning if you STICK  = " << p_stick  << "\n";
    cout << "Probability of winning if you SWITCH = " << p_switch << "\n";

    if (p_switch > p_stick) {
        cout << "Conclusion: You should SWITCH doors.\n";
    } else if (p_switch < p_stick) {
        cout << "Conclusion: You should STICK with your first choice (rare!).\n";
    } else {
        cout << "Conclusion: It doesn't matter (probabilities look equal).\n";
    }

    return 0;
}

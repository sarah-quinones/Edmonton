#include <iostream>
#include <string>
#include <vector>

using namespace std;

string weekday(int dd, int mm, int yy) {
    int rst = dd + ((153 * (mm + 12 * ((14 - mm) / 12) - 3) + 2) / 5) + (365 * (yy + 4800 - ((14 - mm) / 12))) + ((yy + 4800 - ((14 - mm) / 12)) / 4) - ((yy + 4800 - ((14 - mm) / 12)) / 100) + ((yy + 4800 - ((14 - mm) / 12)) / 400) - 32045;
    static vector<string> days_of_the_week = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    return days_of_the_week[((rst + 1) % 7)];
}

int main(int argc, char* argv[]) {
    int sunday_count = 0;
    for(int y = 1901; y <= 2000; y++) {
        for(int m = 1; m < 13; m++) {
            if(weekday(1, m, y) == "Sunday") {
                sunday_count++;
            }
        }
    }
    cout << sunday_count << endl;
    return 0;
}
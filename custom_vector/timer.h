#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <fstream>
#include <vector>

using accuracy = std::chrono::milliseconds;

class Stopwatch
{
    std::chrono::time_point<std::chrono::high_resolution_clock> start{};
    std::chrono::time_point<std::chrono::high_resolution_clock> end{};
    long time_elapsed = 0;
    bool stopped = false;
    std::string name;
    int id;

public:
    explicit Stopwatch(int _id, std::string _name);

    void stopwatch_start();
    void stopwatch_pause();
    long stopwatch_stop();
    long get_time_elapsed() const;
    long clear_time_elapsed();
    std::string get_name() const { return name; }

    int get_id() const;
};

class Timer
{
    std::string content;
    std::vector<Stopwatch> watches;
    bool times_written = false;

public:
    ~Timer();

    void initialize_watch(int watch_id, std::string watch_name);
    bool start_watch(int watch_id);
    bool pause_watch(int watch_id);
    bool stop_watch(int watch_id, std::string msg);
    long get_time_elapsed(int watch_id) const;
    void write_to_file(const std::string &filename) const;
    void write_times(const std::string &filename);
};

#endif // TIMER_H

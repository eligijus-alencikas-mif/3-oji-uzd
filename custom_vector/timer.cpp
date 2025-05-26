#include "timer.h"

Stopwatch::Stopwatch(const int _id, const std::string _name) : id(_id), name(_name) {}

void Stopwatch::stopwatch_start()
{
    this->start = std::chrono::high_resolution_clock::now();
    stopped = false;
}

void Stopwatch::stopwatch_pause()
{
    this->end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<accuracy>(this->end - this->start);
    time_elapsed += duration.count();
    stopped = true;
}

long Stopwatch::stopwatch_stop()
{
    if (stopped)
    {
        return time_elapsed;
    }
    this->end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<accuracy>(this->end - this->start);
    time_elapsed += duration.count();
    stopped = true;
    return clear_time_elapsed();
}

long Stopwatch::get_time_elapsed() const
{
    if (!stopped)
    {
        const auto mid = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<accuracy>(mid - this->start);
        return duration.count();
    }
    return time_elapsed;
}

long Stopwatch::clear_time_elapsed()
{
    const long elapsed = time_elapsed;
    time_elapsed = 0;
    return elapsed;
}

int Stopwatch::get_id() const
{
    return id;
}

// --------------------------------------------------------------------------------
// Timer

Timer::~Timer()
{
    if (!times_written)
    {
        write_times("laikai.txt");
    }
}

void Timer::initialize_watch(const int watch_id, std::string watch_name)
{
    watches.emplace_back(watch_id, watch_name);
}

bool Timer::start_watch(const int watch_id)
{
    for (auto &watch : watches)
    {
        if (watch.get_id() == watch_id)
        {
            watch.stopwatch_start();
            return true;
        }
    }
    return false;
}

bool Timer::pause_watch(const int watch_id)
{
    for (auto &watch : watches)
    {
        if (watch.get_id() == watch_id)
        {
            watch.stopwatch_pause();
            return true;
        }
    }
    return false;
}

bool Timer::stop_watch(const int watch_id, std::string msg)
{
    for (auto &watch : watches)
    {
        if (watch.get_id() == watch_id)
        {
            long time = watch.stopwatch_stop();
            msg += " (" + std::to_string(time) + " milliseconds)\n";
            content.append(msg);
            return true;
        }
    }
    return false;
}

long Timer::get_time_elapsed(const int watch_id) const
{
    for (auto &watch : watches)
    {
        if (watch.get_id() == watch_id)
        {
            return watch.get_time_elapsed();
        }
    }
    return -1;
}

void Timer::write_to_file(const std::string &filename) const
{
    std::ofstream log_file(filename);
    log_file << this->content;
    log_file.close();
}

void Timer::write_times(const std::string &filename)
{
    std::ofstream log_file(filename);
    for (const auto &watch : watches)
    {
        log_file << watch.get_name() << ": " << (double)watch.get_time_elapsed() / 1000 << " sek.\n";
    }
    log_file.close();
    this->times_written = true;
}

#pragma once

class Application {
    public:
        static Application &get_instance();
        void run();
    
    private:
        Application() = default;
        Application(const Application &) = default;
        void operator=(const Application &) = delete;
        Application(Application &&) noexcept = default;
        Application &operator=(Application &&) noexcept = default;

        static Application *instance;
};
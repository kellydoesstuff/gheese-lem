class PID {
    public:
        double output;
        double error;
        double target;
        double prevError;
        double integral;
        double derivative;
        long time;
        long prevTime;
        double kP;
        double kI;
        double kD;
        double startI;
        
        PID(double _p, double _i, double _d, double _startI);
        
    
        struct exit_condition_ {
            int small_exit_time = 0;
            double small_error = 0;
            int big_exit_time = 0;
            double big_error = 0;
            int velocity_exit_time = 0;
            int mA_timeout = 0;
        };

        double compute (double _error);
    
    private:
        int i = 0, j = 0, k = 0, l = 0;
        bool is_mA = false;
        void reset_timers();
};
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
        
    
        struct exitCondition {
            int smallExitTime = 0;
            double smallError = 0;
            int bigExitTime = 0;
            double bigError = 0;
            int veloExitTime = 0;
            int mATimeout = 0;
        };

        void setExitCondition (int _smallExitTime, double _smallError, int _bigExitTime, double _bigError, int _veloExitTime, int _mATimeout);

        double compute (double _error);

        exitCondition exit;
    
    private:
        int i = 0, j = 0, k = 0, l = 0;
        bool is_mA = false;
        void resetTimers();
};
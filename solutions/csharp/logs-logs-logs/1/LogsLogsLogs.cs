public enum LogLevel
{
    Unknown,
    Trace,
    Debug,
    Info = 4,
    Warning,
    Error,
    Fatal = 42
}

static class LogLine
{
    
    public static LogLevel ParseLogLevel(string logLine) => logLine switch
    {
            _ when logLine.Contains("[TRC]") => LogLevel.Trace,
            _ when logLine.Contains("[DBG]") => LogLevel.Debug,
            _ when logLine.Contains("[INF]") => LogLevel.Info,
            _ when logLine.Contains("[WRN]") => LogLevel.Warning,
            _ when logLine.Contains("[ERR]") => LogLevel.Error,
            _ when logLine.Contains("[FTL]") => LogLevel.Fatal,
            _ => LogLevel.Unknown
    };

    public static string OutputForShortLog(LogLevel logLevel, string message) => $"{(int)logLevel}:{message}";
    
}

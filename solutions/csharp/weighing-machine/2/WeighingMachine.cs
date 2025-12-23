class WeighingMachine
{
    public WeighingMachine(int precision) => Precision = precision;

    public int Precision { get; init; }
    
    private double _weight;
    public double Weight
    {
        get => _weight;
        set
        {
            ArgumentOutOfRangeException.ThrowIfNegative(value);
            _weight = value;
        }
    }
    
    public double TareAdjustment { get; set; } = 5.0;

    public string DisplayWeight
    {
        get
        {
            return $"{Math.Round(Weight - TareAdjustment, Precision).ToString($"F{Precision}")} kg";
        }
    }
}

class WeighingMachine
{
    public WeighingMachine(int precision) => Precision = precision;

    public int Precision { get; init; }
    
    private double _weight;
    public double Weight
    {
        get => _weight;
        set => _weight = value >= 0.0 ? value : throw new ArgumentOutOfRangeException();
    }
    
    private double _tareAdjustment = 5.0;
    public double TareAdjustment
    {
        get => _tareAdjustment;
        set => _tareAdjustment = value;
    }

    public string DisplayWeight
    {
        get
        {
            return $"{(Weight - TareAdjustment).ToString($"F{Precision}")} kg";
        }
    }
}

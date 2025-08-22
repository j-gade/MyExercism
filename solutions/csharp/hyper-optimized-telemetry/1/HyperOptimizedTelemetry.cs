using System;

public static class TelemetryBuffer
{
    public static byte[] ToBuffer(long reading)
    {
        byte[] buffer = new byte[9];
        byte[] payload;
        int prefix;
        switch (reading)
        {
            case < Int32.MinValue:
            case > UInt32.MaxValue:
                prefix = 256 - sizeof(Int64);
                payload = BitConverter.GetBytes(reading);
                break;
            case < Int16.MinValue:
            case > UInt16.MaxValue and <= Int32.MaxValue:
                prefix = 256 - sizeof(Int32);
                payload = BitConverter.GetBytes((Int32)reading);
                break;
            case < 0:
                prefix = 256 - sizeof(Int16);
                payload = BitConverter.GetBytes((Int16)reading);
                break;
            case >= 0 and <= UInt16.MaxValue:
                prefix = sizeof(UInt16);
                payload = BitConverter.GetBytes((UInt16)reading);
                break;
            case > UInt16.MaxValue and <= UInt32.MaxValue:
                prefix = sizeof(UInt32);
                payload = BitConverter.GetBytes((UInt32)reading);
                break;
        }

        buffer[0] = (byte)prefix;
        Array.Copy(payload, payload.GetLowerBound(0), buffer, buffer.GetLowerBound(0) + 1, payload.Length);
        return buffer;
    }

    public static long FromBuffer(byte[] buffer)
    {
        switch (buffer[0])
        {
            case sizeof(UInt16):
                return (long)BitConverter.ToUInt16(buffer[1..]);
                break;
            case sizeof(UInt32):
                return (long)BitConverter.ToUInt32(buffer[1..]);
            case (256 - sizeof(Int16)):
                return (long)BitConverter.ToInt16(buffer[1..]);
                break;
            case (256 - sizeof(Int32)):
                return (long)BitConverter.ToInt32(buffer[1..]);
                break;
            case (256 - sizeof(Int64)):
                return BitConverter.ToInt64(buffer[1..]);
                break;
            default:
                return 0L;
                break;
        }
    }
}

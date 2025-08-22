// Package circular implements a circular buffer of bytes supporting both overflow-checked writes
// and unconditional, possibly overwriting, writes.
package circular

import "io"

// A Buffer is a fixed-size circular buffer of bytes implementing the io.ByteReader and
// io.ByteWriter interfaces. A new buffer must be created using NewBuffer, as the zero
// value of the Buffer is not usable.
type Buffer struct {
    capacity int
    length int
    writeIdx int
    readIdx int
    data []byte
}

// NewBuffer returns a new circular buffer ready to use.
func NewBuffer(size int) *Buffer {
	b := Buffer{capacity: size}
    b.data = make([]byte, size)
    return &b
}

// ReadByte returns the next available byte in the buffer, or io.EOF if the buffer is empty.
func (b *Buffer) ReadByte() (byte, error) {
	if b.length == 0 {
        return 0, io.EOF
    }
    result := b.data[b.readIdx]
    b.length--
    b.readIdx = (b.readIdx + 1) % b.capacity
    return result, nil
}

// WriteByte attempts to write a byte to the buffer, and returns io.EOF if the buffer is full.
func (b *Buffer) WriteByte(c byte) error {
	if b.length >= b.capacity {
        return io.EOF
    }
    b.data[b.writeIdx] = c
    b.length++
    b.writeIdx = (b.writeIdx + 1) % b.capacity
    return nil
}

// Overwrite unconditionally writes to the buffer without returning an error. If the buffer
// is full, Overwrite writes over the oldest data in the buffer.
func (b *Buffer) Overwrite(c byte) {
    if b.length >= b.capacity {
		_, _ = b.ReadByte()
        }
    _ = b.WriteByte(c)
}

// Reset resets the buffer to its empty state.
func (b *Buffer) Reset() {
	b.length = 0
    b.writeIdx = 0
    b.readIdx = 0
}

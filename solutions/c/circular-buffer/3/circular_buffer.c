#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "circular_buffer.h"

circular_buffer_t* new_circular_buffer(size_t capacity)
{
    assert(capacity);

    circular_buffer_t* new_buffer =
        (circular_buffer_t*)malloc(sizeof(circular_buffer_t));
        assert(new_buffer != NULL);

        new_buffer->data = (buffer_value_t*)calloc(capacity, sizeof(buffer_value_t));
        assert(new_buffer->data != NULL);

        new_buffer->cap = capacity;
        new_buffer->write_idx = 0;
        new_buffer->read_idx = 0;
        new_buffer->len = 0;

        return new_buffer;
}

void clear_buffer(circular_buffer_t* buffer)
{
    assert(buffer != NULL);

    buffer->write_idx = buffer->read_idx = buffer->len = 0;
}

void delete_buffer(circular_buffer_t* buffer)
{
    assert(buffer != NULL && buffer->data != NULL);

    free(buffer->data);
    buffer->data = NULL;
    free(buffer);
    buffer = NULL;
    return;
}

static inline bool is_empty(circular_buffer_t* buffer)
{
    return (buffer->len == 0);
}

static inline bool is_full(circular_buffer_t* buffer)
{
    return (buffer->len >= buffer->cap);
}

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    assert(buffer != NULL);
    if (is_full(buffer)) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    assert(buffer->write_idx < buffer->cap);
    buffer->data[buffer->write_idx] = value;
    buffer->write_idx = (buffer->write_idx + 1) % (buffer->cap);
    ++(buffer->len);
    assert(buffer->len <= buffer->cap);
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    if (is_full(buffer)) {
        buffer_value_t discard;
        read(buffer, &discard);
    }
    return write(buffer, value);
}

int16_t read(circular_buffer_t* buffer, buffer_value_t* value)
{
    assert(buffer != NULL && value != NULL);
    if (is_empty(buffer)) {
        errno = ENODATA;
        return EXIT_FAILURE;
    }

    assert(buffer->read_idx < buffer->cap);

    *value = buffer->data[buffer->read_idx];
    buffer->read_idx = (buffer->read_idx + 1) % (buffer->cap);
    assert(buffer->len > 0);
    --(buffer->len);
    return EXIT_SUCCESS;
}

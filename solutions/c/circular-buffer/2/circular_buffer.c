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

        new_buffer->buffer = (buffer_value_t*)calloc(capacity, sizeof(buffer_value_t));
        assert(new_buffer->buffer != NULL);

        new_buffer->capacity = capacity;
        new_buffer->head = 0;
        new_buffer->tail = 0;
        new_buffer->size = 0;

        return new_buffer;
}

void clear_buffer(circular_buffer_t* buffer)
{
    assert(buffer != NULL);

    buffer->head = buffer->tail = buffer->size = 0;
}

void delete_buffer(circular_buffer_t* buffer)
{
    assert(buffer != NULL);

    free(buffer->buffer);
    buffer->buffer = NULL;
    free(buffer);
    buffer = NULL;
    return;
}

static bool is_empty(circular_buffer_t* buffer)
{
    return (buffer->size == 0);
}

static bool is_full(circular_buffer_t* buffer)
{
    return (buffer->size == buffer->capacity);
}

int16_t write(circular_buffer_t* buffer, buffer_value_t value)
{
    assert(buffer != NULL);
    if (is_full(buffer)) {
        errno = ENOBUFS;
        return EXIT_FAILURE;
    }

    size_t next = buffer->head + 1;
    if (next == buffer->capacity)
        next = 0;
    assert(buffer->head < buffer->capacity);
    buffer->buffer[buffer->head] = value;
    buffer->head = next;
    ++(buffer->size);
    assert(buffer->size <= buffer->capacity);
    return EXIT_SUCCESS;
}

int16_t overwrite(circular_buffer_t* buffer, buffer_value_t value)
{
    if (is_full(buffer)) {
        buffer_value_t oldest;
        read(buffer, &oldest);
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

    assert(buffer->tail < buffer->capacity);
    size_t next = buffer->tail + 1;
    if (next == buffer->capacity)
        next = 0;
    *value = buffer->buffer[buffer->tail];
    buffer->tail = next;
    assert(buffer->size > 0);
    --(buffer->size);
    return EXIT_SUCCESS;
}

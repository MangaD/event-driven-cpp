# I/O Events in C++ Using `select()` and `poll()`

I/O event handling is essential for building responsive, non-blocking applications—especially in network programming. This document explains how to use two common system calls, `select()` and `poll()`, for monitoring file descriptors and handling I/O events.

## Overview

- **Event-Driven I/O:**  
  Instead of blocking on a single I/O operation, an application can monitor multiple file descriptors for readiness to perform I/O (e.g., reading or writing) and react when an event occurs.

- **`select()`:**  
  The `select()` system call allows you to monitor multiple file descriptors to see if any of them are ready for I/O. It uses sets of file descriptors and supports a timeout mechanism.

- **`poll()`:**  
  The `poll()` system call serves a similar purpose as `select()` but offers a simpler interface and better scalability for a larger number of file descriptors.

## Using `select()`

### Example Code

```cpp
#include <sys/select.h>
#include <iostream>
#include <unistd.h>

int main() {
    // Initialize the file descriptor set
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    // Set a timeout of 5 seconds
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;

    std::cout << "Waiting for input (5s timeout)..." << std::endl;
    
    // Wait for input on STDIN_FILENO
    int result = select(STDIN_FILENO + 1, &read_fds, nullptr, nullptr, &timeout);

    if (result > 0 && FD_ISSET(STDIN_FILENO, &read_fds)) {
        std::cout << "Input received!" << std::endl;
    } else {
        std::cout << "Timeout or error occurred." << std::endl;
    }
    return 0;
}
```

### Explanation

- **FD_SET and FD_ZERO:**  
  The macros `FD_ZERO` and `FD_SET` initialize and modify an `fd_set`, a data structure used by `select()` to represent file descriptor sets.
  
- **Timeout Mechanism:**  
  The `timeval` structure specifies how long `select()` should wait for an event before timing out.

- **select():**  
  Monitors the file descriptors in `read_fds`. When an event occurs (e.g., input is ready on `STDIN_FILENO`), `select()` returns, and you can check which descriptors are ready.

## Using `poll()`

### Example Code

```cpp
#include <poll.h>
#include <iostream>
#include <unistd.h>

int main() {
    // Create a pollfd structure for STDIN_FILENO
    struct pollfd pfd;
    pfd.fd = STDIN_FILENO;
    pfd.events = POLLIN;  // Monitor for input events

    std::cout << "Waiting for input (5s timeout)..." << std::endl;
    
    // Wait for input with a timeout of 5000 milliseconds
    int result = poll(&pfd, 1, 5000);

    if (result > 0 && (pfd.revents & POLLIN)) {
        std::cout << "Input received!" << std::endl;
    } else {
        std::cout << "Timeout or error occurred." << std::endl;
    }
    return 0;
}
```

### Explanation

- **pollfd Structure:**  
  The `pollfd` structure specifies:
  - `fd`: the file descriptor to monitor (e.g., `STDIN_FILENO`).
  - `events`: the events to watch for (e.g., `POLLIN` indicates data is ready for reading).
  - `revents`: a field where `poll()` returns the actual events that occurred.
  
- **poll():**  
  The `poll()` call waits for events on the provided file descriptors. It returns the number of file descriptors with events, or 0 if the call times out.

## Choosing Between `select()` and `poll()`

- **Use `select()` if:**
  - The number of file descriptors is small.
  - Portability is a concern (as `select()` is widely available on many Unix-like systems).

- **Use `poll()` if:**
  - You need to monitor a larger number of file descriptors.
  - You prefer a simpler, more scalable interface without the fixed limits (like `FD_SETSIZE`) associated with `select()`.

## Conclusion

Both `select()` and `poll()` are effective for event-driven I/O. Your choice will depend on the specific requirements of your application, such as the number of file descriptors you need to monitor and the complexity of your I/O operations. For further details, refer to the manual pages:
- [select(2)](https://man7.org/linux/man-pages/man2/select.2.html)
- [poll(2)](https://man7.org/linux/man-pages/man2/poll.2.html)

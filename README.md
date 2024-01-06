# minitalk

## Overview

Minitalk is a client-server communication project for sending messages using binary encoding and signal handling.

## Client

- Takes two parameters: server PID and message to send.
- Validates the server's PID.
- Sends the message to the server, encoding it bit by bit.

## Server

- Sets up a signal handler using sigaction.
- Prints its own PID.
- Enters an endless loop to receive signals SIGUSR1 and SIGUSR2.
- Reconstructs the message bit by bit until it reaches a null terminator.
- Prints the received message.

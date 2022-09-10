from concurrent.futures import thread
import threading
import time

sem = threading.Semaphore(value=0)
lock = threading.Lock()
buffer = []

def consumer():
    while True:
        sem.acquire()
        lock.acquire()
        print('Thread', threading.get_ident(), 'got', buffer.pop())
        lock.release()
        time.sleep(3)

t1 = threading.Thread(target=consumer)
t2 = threading.Thread(target=consumer)
t1.start()
t2.start()

while True:
    val = input('')
    lock.acquire()
    buffer.append(val)
    lock.release()
    sem.release()

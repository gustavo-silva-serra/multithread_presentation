import threading
import time
import random

lock = threading.Lock()

def correr(name):
    metros = 0
    while metros < 75:
        problema = random.choice([[0,''], [1, 'colocando agua radiador'], [2, 'completando oleo'], [5, 'trocando pneu furado']])
        if problema[0]:
            lock.acquire()
            print('O carro', name, 'esta', problema[1])
            lock.release()
        time.sleep(problema[0])
        metros = metros + random.choice([5, 7, 10])
        lock.acquire()
        print('O carro', name, 'avancou ate', metros, 'metros')
        lock.release()
    lock.acquire()
    print('\t\t-## O carro', name, 'cruzou a linha de chegada! ##-')
    lock.release()

random.seed(time.time())
carro1 = threading.Thread(target=correr, args=('Chevette',))
carro2 = threading.Thread(target=correr, args=('Ka',))
carro3 = threading.Thread(target=correr, args=('Clio',))
carro4 = threading.Thread(target=correr, args=('Uno',))
carro1.start()
carro2.start()
carro3.start()
carro4.start()
carro1.join()
carro2.join()
carro3.join()
carro4.join()
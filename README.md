# 🧘‍♂️ Philosophers

[![License](https://img.shields.io/badge/license-MIT-lightgrey)](LICENSE)

`Philosophers` is a multithreaded program developed as part of the 42 School curriculum.  
It simulates the famous **Dining Philosophers Problem**, exploring concepts of concurrency, synchronization, and thread management in C.

---

## 🧠 Project Summary

- Written in **C**, compliant with the 42 Norm coding standard.  
- Uses **POSIX threads (pthreads)** to model philosopher behavior.  
- Demonstrates synchronization using **mutexes** to prevent data races and deadlocks.  
- Simulates concurrent actions like eating, sleeping, and thinking.  
- Focuses on **timing precision**, **race condition prevention**, and **deadlock avoidance**.

---

## 📋 Features

### ✅ Mandatory

- Each philosopher is represented as a **thread**.  
- Forks are represented by **mutexes** to control access.  
- The simulation stops when:
  - A philosopher dies (fails to eat within a given time).  
  - All philosophers have eaten a predefined number of times (if specified).  
- Parameters are received as command-line arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_meals]
```

- Logs each philosopher’s state changes in real time (e.g., "is eating", "is sleeping", "died") with timestamps.

### 🧩 Bonus (if implemented)

- Use of **processes** instead of threads, with **semaphores** for synchronization.  
- Advanced process management and inter-process communication.  
- Optimized timing and reduced resource contention.  
- Enhanced visual or debugging output.

---

## 🚀 How to Use

Clone and build the project:

```bash
git clone https://github.com/IzaroArbaiza/Philosophers.git
cd Philosophers && make
```

Run the program with desired parameters:
```bash
./philo 5 800 200 200
```

or, with a meal limit:
```bash
./philo 5 800 200 200 5
```

Example Output:
```bash
0 1 is thinking
100 1 has taken a fork
102 1 is eating
303 1 is sleeping
505 1 is thinking
...
```

## ⚙️ Parameters Explained

| Argument                 | Description                                                                 |
|--------------------------|-----------------------------------------------------------------------------|
| `number_of_philosophers` | Number of philosophers and forks                                            |
| `time_to_die`            | Time (ms) before a philosopher dies if not eating                           |
| `time_to_eat`            | Time (ms) it takes to eat                                                   |
| `time_to_sleep`          | Time (ms) it takes to sleep                                                 |
| `[number_of_meals]`      | (Optional) Stop simulation when all philosophers have eaten this many times |



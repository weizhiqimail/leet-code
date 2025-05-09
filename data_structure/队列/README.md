# 队列

# 1.1 什么是队列？

- 队列是存放数据对象的一种容器，其中的数据对象也按照线性的逻辑次序排列。队列结构同样支持对象的插入和删除，但是两种操作的范围仅限于队列的两端。
- 队列规定：**元素只能从一端添加，即入队(enqueue)，从另一端删除，即出队(dequeue)**。 
- 队列可以理解为排队，所以它的特点是**先进先出，后进后出**，有着非常明确的顺序。 
- 用**数组实现的队列**叫作**顺序队列**，用**链表实现的队列**叫作**链式队列**。

## 1.2 队列的分类

- 有普通队列，双端队列，循环队列，阻塞队列，并发队列。

**阻塞队列** ：阻塞队列其实就是在队列基础上增加了阻塞操作。简单来说，就是在队列为空的时候，从队头取数据会被阻塞。因为此时还没有数据可取，直到队列中有了数据才能返回；如果队列已经满了，那么插入数据的操作就会被阻塞，直到队列中有空闲位置后再插入数据，然后再返回。在多线程情况下，会有多个线程同时操作队列，这个时候就会存在线程安全问题。

**并发队列** ：最简单直接的实现方式是直接在 enqueue()、dequeue() 方法上加锁，但是锁粒度大并发度会比较低，同一时刻仅允许一个存或者取操作。实际上，基于数组的循环队列，利用 CAS 原子操作，可以实现非常高效的并发队列。这也是循环队列比链式队列应用更加广泛的原因。

## 1.3 队列在线程池中的应用

**问题** ：线程池没有空闲线程时，新的任务请求线程资源时，线程池该如何处理？各种处理策略又是如何实现的呢？

- 我们一般有两种处理策略：
  - **非阻塞的处理方式**，直接拒绝任务请求；
  - **阻塞的处理方式**，将请求排队，等到有空闲线程时，取出排队的请求继续处理。那如何存储排队的请求呢？

- 我们希望公平地处理每个排队的请求，先进者先服务，所以队列这种数据结构很适合来存储排队请求。我们前面说过，队列有基于链表和基于数组这两种实现方式。这两种实现方式对于排队请求又有什么区别呢？

- **基于链表的实现方式**，可以实现一个支持无限排队的无界队列（unbounded queue），但是可能会导致过多的请求排队等待，请求处理的响应时间过长。所以，针对响应时间比较敏感的系统，基于链表实现的无限排队的线程池是不合适的。
- **基于数组实现的有界队列（bounded queue）**，队列的大小有限，所以线程池中排队的请求超过队列大小时，接下来的请求就会被拒绝，这种方式对响应时间敏感的系统来说，就相对更加合理。不过，设置一个合理的队列大小，也是非常有讲究的。队列太大导致等待的请求太多，队列太小会导致无法充分利用系统资源、发挥最大性能。

- 除了前面讲到队列应用在线程池请求排队的场景之外，队列可以应用在任何有限资源池中，用于排队请求，比如**数据库连接池**等。实际上，对于大部分资源有限的场景，当没有空闲资源时，基本上都可以通过“队列”这种数据结构来实现请求排队。

# 2. 不同队列的实现

我们可以采用数组来实现普通队列的双端队列。

## 2.1 普通队列

![普通队列 JavaScript](./Queue.js)

## 2.2 双端队列

+ 两端都可以插入和删除，既支持 FIFO，也可以当作栈使用（LIFO）

![双端队列 JavaScript](./Deque.js)

## 2.3 循环队列

+ 队尾指针达到数组末尾时可“循环”回头，从头部空位继续插入。

![循环队列 JavaScript](./CircularQueue.js)

# 3. 队列的应用
## 3.1 方块舞的舞伴分配问题

方块舞，男生女生各一队，每队各出一个人，形成一男一女搭配，如果某一队没人，那么分配舞伴就结束，同时把正在等待的人告知大家。

```typescript
let text = `
F Allison McMillan
M Frank Opitz
M Mason McMillan
M Clayton Ruff
F Cheryl Ferenback
M Raymond Williams
F Jennifer Ingram
M Bryan Frazer
M David Durr
M Danny Martin
F Aurora Adney
`;

class Dancer {
  name: string;
  sex: string;

  constructor(name: string, sex: string) {
    this.name = name;
    this.sex = sex;
  }
}

function getDancer(males: Queue<Dancer>, females: Queue<Dancer>) {
  let names = text.split('\n').filter(Boolean);
  for (let i = 0; i < names.length; i++) {
    names[i] = names[i].trim();
  }

  for (let i = 0; i < names.length; i++) {
    let [sex, name] = names[i].split(' ');
    if (sex === 'F') {
      females.enqueue(new Dancer(name, sex));
    } else {
      males.enqueue(new Dancer(name, sex));
    }
  }
}

function dance(males: Queue<Dancer>, females: Queue<Dancer>) {
  console.log('The dancer partners are: \n');
  while (!females.isEmpty() && !males.isEmpty()) {
    let person = females.dequeue() as Dancer;
    console.log('----- female dancer is: ', person.name);
    person = males.dequeue() as Dancer;
    console.log('-----   male dancer is: ', person.name);
  }
}

export function start() {
  const females = new Queue<Dancer>();
  const males = new Queue<Dancer>();

  getDancer(males, females);

  dance(males, females);

  if (!females.isEmpty()) {
    console.log('female ' + females.front().name + ' is waiting to dance');
  }

  if (!males.isEmpty()) {
    console.log('male ' + males.front().name + ' is waiting to dance');
  }
}
```

## 3.2 基数排序

基数排序是指对一组数字根据基来排序，一位数的基是 1，两位数的基是 10，三位数的基是 100，以此类推...

比如一组 0-99 的数据，首先对数据进行个位排序，然后再进行十位排序，每次排序的顺序通过 Queue 保存，这样就可以得到最终排序的结果。

```typescript
enum Digit {
  ONE = 1,
  TEN = 10
}

function distribute(nums: number[], queues: Array<Queue<number>>, digit: Digit) {
  for (let i = 0; i < nums.length; ++i) {
    const num = nums[i];
    if (digit === Digit.ONE) {
      queues[num % 10].enqueue(num);
    } else {
      queues[Math.floor(num / 10)].enqueue(num);
    }
  }
}

function collect(queues: Array<Queue<number>>, nums: Array<number | undefined>) {
  let i = 0;
  for (let digit = 0; digit < 10; ++digit) {
    while (!queues[digit].isEmpty()) {
      nums[i++] = queues[digit].dequeue();
    }
  }
}

export function start() {
  let nums = [];
  let queues: Queue<number>[] = [];

  for (let i = 0; i < 10; i++) {
    queues[i] = new Queue<number>();
    nums[i] = Math.floor(Math.floor(Math.random() * 101));
  }
  
  // 个位排序
  distribute(nums, queues, Digit.ONE);

  // 存放数组
  collect(queues, nums);

  // 十位排序
  distribute(nums, queues, Digit.TEN);

  // 存放数组
  collect(queues, nums);
  
  // 获取结果
  console.log(nums);

}
```

# SUSU_ThreadPool
A simple C++11 Thread Pool made by ZhengXuan-Xie

if you find some problem,please give me an issue.So that i can fix it.

# Referent
This project was designed inspired by the ThreadPool,which the link is https://github.com/progschj/ThreadPool
ThreadPool is useful but not suitable fo me，so I add some new function。

# Features

## Task Queue:
  Task is a function that you want to run.Like this:
  
    int function_name(char str){
    
      function_code__xxxx 
      
      return 0;
      
    }
  
  you can use add_task to provide a task to Thread_Controler.Like this:

    int main(){
      Thread_Controler* p = Thread_Controler::get_Thread_Controler();
  
      p->add_tesk(function_name,'s');
  }
  
  Thread_Controler will allocate this Task to a Worker's Task Queue.
  
  Worker is running in a thread.when it running,it will try to get a Task from it's Task Queue,and try to finish the task.
  
## Load Balance:
  
  the Thread_Controler will try to allocate Tasks evenly.

## No thundering herd
  
  because the whole Task-system is not based on event,so there is no thundering herd.
  
## Dynamic expansion
  
  Thread_Controler will add or reduse the counts of thread in some situation.
  
## Result Queue:
  Worker have a queue to restore the task result.if you don't need the result,remember to remove it to avoid space occupation.

  Result Queue is a future queue,Like this:

  ::std::queue< ::std::future<int> > task_result_queue;

  if you want to store the future value,you can use this code:

  task_result_queue.emplace(enqueue(::std::forward<F>(f), ::std::forward<Args>(args)...));

  if not,you can use this code to avoid store the return value:

  enqueue(::std::forward<F>(f), ::std::forward<Args>(args)...);

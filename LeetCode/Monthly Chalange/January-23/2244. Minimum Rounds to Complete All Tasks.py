class Solution:
    def minimumRounds(self, tasks: List[int]) -> int:
        task_counts = {}
        for task in tasks:
            if task not in task_counts:
                task_counts[task] = 0
            task_counts[task] += 1
        
        ans=0 
        set_tasks = set(tasks)
        for task in set_tasks:
            if task_counts[task] == 1:
                return -1
            elif task_counts[task] % 3 == 0:
                ans += task_counts[task]//3
            elif task_counts[task] % 3 == 1:
                ans += (((task_counts[task]-4)//3)+2)
            else:
                ans += ((task_counts[task]//3)+1)
        return ans
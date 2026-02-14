
    def quickSort(arr, left, right, k):
        if left >= right:
            return
        
        mid = left + (right - left) // 2
        arr[left], arr[mid] = arr[mid], arr[left]
        pivot = arr[left]
        L, R = left + 1, right

        while L <= R:
            while L <= R and arr[L] <= pivot: 
                L += 1
            while L <= R and arr[R] >= pivot: 
                R -= 1
            if L < R:
                arr[L], arr[R] = arr[R], arr[L]
                L += 1
                R -= 1
            else:
                L += 1
        
        arr[left], arr[R] = arr[R], arr[left]
        quickSort(arr, left, R-1, k)
        quickSort(arr, R+1, right, k)


    def quickSelect(arr, left, right, k):
        if left >= right:
            return
        
        mid = left + (right - left) // 2
        arr[left], arr[mid] = arr[mid], arr[left]
        pivot = arr[left]
        L, R = left + 1, right

        while L <= R:
            while L <= R and arr[L] <= pivot: 
                L += 1
            while L <= R and arr[R] >= pivot: 
                R -= 1
            if L < R:
                arr[L], arr[R] = arr[R], arr[L]
                L += 1
                R -= 1
            else:
                L += 1
        
        arr[left], arr[R] = arr[R], arr[left]
        if k < R:
            self.quickSelect(arr, left, R-1, k)
        elif k > R:
            self.quickSelect(arr, R+1, right, k)

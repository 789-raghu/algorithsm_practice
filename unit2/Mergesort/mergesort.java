package Mergesort;

import java.util.*;

public class mergesort {
    public static void merge(int start,int end ,int mid,int[] arr){
        int i = start,j = mid+1,k = 0;
        int[] temp = new int[end-start+1];

        while(i<=mid && j<=end){
            if(arr[i]<arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }

        while(i<=mid){
            temp[k++] = arr[i++];
        }
        
        while(j<=end){
            temp[k++] = arr[j++];
        }

        for(int duplicate = 0;duplicate<k;duplicate++){
            arr[start+duplicate] = temp[duplicate];
        }
        return;
    }

    public static void mergeSort(int start,int end,int[] arr){
        if(start<end){
            int mid = (start+end)/2;
            mergeSort(start, mid, arr);
            mergeSort(mid+1, end, arr);
            merge(start, end, mid, arr);
            return;
        }
        return;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the size of the array : ");
        int size = scanner.nextInt();

        int[] array = new int[size];
        for(int i = 0;i<size;i++){
            System.out.printf("arr[%d]: ",i);
            array[i] = scanner.nextInt();
        }
        mergeSort(0, size-1, array);
        System.out.println(Arrays.toString(array));
        scanner.close();
    }
}

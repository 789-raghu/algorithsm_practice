package TowersOfHanoi;

public class towersofHanoi {
    public static void towersOfHanoi(int diskNumber,char source,char destination,char helper){
        if(diskNumber==1){
            System.out.printf("Move disk %d from %c to %c\n",diskNumber,source,destination);
            return;
        }
        towersOfHanoi(diskNumber-1, source, helper, destination);
        System.out.printf("Move disk %d from %c to %c\n",diskNumber,source,destination);
        towersOfHanoi(diskNumber-1, helper, destination, source);
    }

    public static void main(String[] args){
        int diskNumber = 3;
        char source = 'a',destination = 'c',helper = 'b';
        towersOfHanoi(diskNumber, source, destination, helper);
    }
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package accountwithsyncusinglock;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 *
 * @author insomniac
 */
public class AccountWithSyncUsingLock {

    private static Account account = new Account();
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        ExecutorService executor = Executors.newCachedThreadPool();
        for(int i=0;i<100;i++)
        {
            executor.execute(new AddAPennyTask());
        }
        executor.shutdown();
        
        while(!executor.isTerminated())
        {
        }
            System.out.println("What is the balance? " + account.getBalance());
    }
    
    public static class AddAPennyTask implements Runnable{

        @Override
        public void run() {
            account.deposit(1);
            //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
        }
        
    }
    
    public static class Account{
        private static Lock lock = new ReentrantLock();
        private int balance=0;
        public int getBalance()
        {
            return balance;
        }
        public void deposit(int amount)
        {
            lock.lock();
            try{
                int newBalance = balance+amount;
                Thread.sleep(5);
                balance = newBalance;
            } catch (InterruptedException ex){
            
            } finally{
                lock.unlock();
            }
            
        }
    }
}

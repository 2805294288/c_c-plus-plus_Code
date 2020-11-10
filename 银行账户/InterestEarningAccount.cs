using System;
using System.Collections.Generic;
using System.Text;

namespace classes
{
    public class InterestEarningAccount : BankAccount
    {
        
        public InterestEarningAccount(string name, decimal initialBalance) : base(name, initialBalance) 
        { 
        }
        //构造函数

        
        public override void PerformMonthEndTransactions()
        {
            if (Balance > 500m)
            {
                var interest = Balance * 0.05m;
                MakeDeposit(interest, DateTime.Now, "apply monthly interest");
            }
        }
        //重写父类方法
    }
}

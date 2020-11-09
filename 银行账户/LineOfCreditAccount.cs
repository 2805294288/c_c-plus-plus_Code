using System;
using System.Collections.Generic;
using System.Text;

namespace classes
{
    class LineOfCreditAccount : BankAccount
    {
        
        public LineOfCreditAccount(string name, decimal initialBalance, decimal creditLimit) : base(name, initialBalance, -creditLimit)
        {
        }
       
        //构造函数
        
        public override void PerformMonthEndTransactions()
        {
            if (Balance < 0)
            {
                
                var interest = -Balance * 0.07m;
                MakeWithdrawal(interest, DateTime.Now, "Charge monthly interest");
            }
        }
        //重写父类方法
        

       
        protected override Transaction CheckWithdrawalLimit(bool isOverdrawn) =>
            isOverdrawn
            ? new Transaction(-20, DateTime.Now, "Apply overdraft fee")
            : default;
        
        //重写父类方法
    }
}
using System;
using System.Collections.Generic;
using System.Text;

namespace classes
{
    public class GiftCardAccount : BankAccount
    {
        // <GiftCardAccountConstruction>
        private decimal _monthlyDeposit = 0m;
        //属性

        public GiftCardAccount(string name, decimal initialBalance, decimal monthlyDeposit = 0) : base(name, initialBalance)
            => _monthlyDeposit = monthlyDeposit;
            //构造函数
        

        
        public override void PerformMonthEndTransactions()
        {
            if (_monthlyDeposit != 0)
            {
                MakeDeposit(_monthlyDeposit, DateTime.Now, "Add monthly deposit");
            }
        }
        //重写父类的方法
    }
}
#ifndef __COMPUTER_H__
#define __COMPUTER_H__ 

class Computer
{
	public:
		virtual void price(int price)
		{
			cpu_ = "";
			ram_ = 0;
		}
	protected:
		string cpu_;
		int ram_;

};

class Dell
{
	public:
		void price(int price)
		{
			cpu_ = "i7";
			ram_ = 2;
			prince_ = price;
		}
	private:
		int price_;	
};
 



#endif  /*__COMPUTER_H__*/

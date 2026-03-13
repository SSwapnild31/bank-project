#include<iostream>
#include<string>
#include<limits>

namespace bnk
{
	enum class acc_type{ saving = 1, current };
	
	struct bank_column{
		int acc_no;
		std::string name;
		double balance;
		acc_type type;
	};

	class bank
	{
		public:
			virtual void read_data() = 0;
			virtual void create_acc() = 0;
			virtual void delete_acc() = 0;
			virtual void update_acc() = 0;
			virtual void search_acc() = 0;
			//virtual void display() = 0;
			virtual void display_all_acc() = 0;
			
			virtual ~bank() {}
	};

	class admin : public bank
	{
		public:
			void read_data() {
				std::cout <<"insert data\n";

				struct bank_column acc;
				
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<"Enter name : ";
				getline(std::cin, acc.name);
				
				std::cout <<"Enter balance : ";
				std::cin >> acc.balance;
				
				int type;
				std::cout <<"1.saving\t2.current\nEnter Acc type : ";
				std::cin >> type;

				if(type == 1)	
					acc.type = acc_type::saving;
				else	
					acc.type = acc_type::current;
			}

			/*void display(){
				std::cout <<"-----------USER DATA-----------"<< std::endl;
				std::cout <<"Acc name    : "<< name << std::endl;
				std::cout <<"Acc number  : "<< acc_no << std::endl;
				std::cout <<"Acc type    : "<< type << std::endl;
				std::cout <<"Acc balance : "<< balance << std::endl;
				std::cout <<"-------------------------------"<< std::endl;
			}*/
			void create_acc() {
				std::cout <<"create acc, ";
				read_data();
				std::cout <<"Account created successfully\n";
			}
			void delete_acc() {
				std::cout <<"Delete account\n";
				
				int number;
				std::cout <<"Enter acc number : ";
				std::cin >> number;
				
			}
			void update_acc() {
				std::cout <<"Update acc\n";
				
				int number;
				std::cout <<"Enter acc number : ";
				std::cin >> number;
			}
			void search_acc() {
				std::cout <<"Search acc\n";
				
				int number;
				std::cout <<"Enter acc number : ";
				std::cin >> number;
			}
			void display_all_acc() {
				std::cout <<"Display all acc\n";
				
			}
	};

	class user : public bank
	{
		public: 
			void send_money(){

			}
			void deposit_money(){

			}
			
	};
};

int main()
{
	bnk::admin adm;
	bnk::user usr;

	std::cout <<"-------------------------------"<< std::endl;
	std::cout <<"            WELCOME            "<< std::endl;
	
	while(true){
		int op;
		std::cout <<"-------------------------------"<< std::endl;
		std::cout <<"1.Create Acc\t2.Update Acc\n3.Search Acc\t4.Delete Acc\n5.Display all\t6.Exit\n";
		std::cout <<"-------------------------------"<< std::endl;
		std::cout <<"Enter option : ";
		std::cin >> op;
		std::cout <<"-------------------------------"<< std::endl;
		
		switch(op)
		{
			case 1 : adm.create_acc();	break;
			case 2 : adm.update_acc();	break;
			case 3 : adm.search_acc();	break;
			case 4 : adm.delete_acc();	break;
			case 5 : adm.display_all_acc();	break;
			case 6 : exit(0);
			default: std::cout <<"  wrong option! Enter again!\n";
		}
	}
}


















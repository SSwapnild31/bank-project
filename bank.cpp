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
			virtual void insert_info() = 0;
			virtual void create_acc() = 0;
			virtual void delete_acc() = 0;
			virtual void update_acc() = 0;
			virtual void search_acc() = 0;
			virtual void display() = 0;
			virtual void display_all_acc() = 0;
			
			virtual ~bank() {}
	};
	
	class user : public bank
	{
		public:
			void insert_info() {
				std::cout <<"insert info\n";

				struct bank_column acc;
				
				std::cout <<"Enter name : ";
				getline(std::cin, acc.name);
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout <<"Enter balance : ";
				std::cin >> acc.balance;
				
				int type;
				std::cout <<"1.saving\t2.current\nEnter Acc type : ";
				std::cin >> type;

				if(type == 1)
					acc.type = acc_type::saving;
				else
					acc.type = acc_type::current;
				
				std::cout <<"Account created successfully\n";
				std::cout <<"-------------------------------"<< std::endl;
			}

			void display(){
				std::cout <<"-----------USER DATA-----------"<< std::endl;
				std::cout <<"Acc name    : "<< name << std::endl;
				std::cout <<"Acc number  : "<< acc_no << std::endl;
				std::cout <<"Acc type    : "<< type << std::endl;
				std::cout <<"Acc balance : "<< balance << std::endl;
				std::cout <<"-------------------------------"<< std::endl;
			}
			void create_acc() {
				std::cout <<"create acc, ";
				insert_info();
			}
			void delete_acc() {
				std::cout <<"delete acc\n";
			}
			void update_acc() {
				std::cout <<"delete acc\n";
			}
			void search_acc() {
				std::cout <<"search acc\n";
			}
			void display_all_acc() {
				std::cout <<"display all acc\n";
			}
	};
};
 
int main()
{
	bnk::user obj;

	std::cout <<"-------------------------------"<< std::endl;
	std::cout <<"            WELCOME            "<< std::endl;
	std::cout <<"-------------------------------"<< std::endl;
	
	while(true){
		int op;
		std::cout <<"1.Create Acc\t2.Update Acc\n3.Search Acc\t4.Delete Acc\n5.Display all\t6.Exit\n";
		std::cout <<"-------------------------------"<< std::endl;
		std::cout <<"Enter option : ";
		std::cin >> op;
		std::cout <<"-------------------------------"<< std::endl;
		
		switch(op)
		{
			case 1 : obj.create_acc();	break;
			case 2 : obj.update_acc();	break;
			case 3 : obj.search_acc();	break;
			case 4 : obj.delete_acc();	break;
			case 5 : obj.display_all_acc();	break;
			case 6 : exit(0);
			default: std::cout <<"  wrong option! Enter again!\n";
				 std::cout <<"-------------------------------"<< std::endl;
		}
	}
}


















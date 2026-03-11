#include<iostream>

namespace bnk{
	struct user{
		int acc_no;
		std::string name;
		double balance;
	};
	
	enum acc_type{ saving, current };

	class bank{
		public:
			void insert_info();
			void create_acc();
			void delete_acc();
			void update_acc();
			void search_acc();
			void display_all_acc();
	};

};

int main()
{


}

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_set>


std::string matchFunc(std::string name, std::vector<std::string> previousPartners, std::vector<std::vector<std::string> > people){
		std::string teamName;
		std::vector<std::string> teamAvail;
		int numberAvailable = 0;
		
		for(long unsigned int i = 0; i < people.size(); i++){ // get team name for given person and number of available peopel
			if(name == people[i][0]) teamName = people[i][1];	
			if(name != people[i][0] && people[i][2] == "1") numberAvailable++;
		}

		if(numberAvailable == 0) return "none"; // no one available to meet


//Meet with someone from another team
		for(long unsigned int i = 0; i < people.size(); i++){
			if(name != people[i][0] && people[i][2] == "1" && teamName != people[i][1]) 
				teamAvail.push_back(people[i][0]);				
		}

		if(!teamAvail.empty()){ 
			std::sort(teamAvail.begin(), teamAvail.end());
			return teamAvail.front();
		}


//Meet with someone who you have never met with
	std::unordered_set<std::string> prevPartnersHash;

	for(long unsigned int i = 0; i < previousPartners.size(); i++){ // put previous parterns in hash table
		prevPartnersHash.insert(previousPartners[i]); 
		}

	
	for(long unsigned int i = 0; i < people.size(); i++){ 
			if(name != people[i][0] && people[i][2] == "1" && prevPartnersHash.find(people[i][0]) == prevPartnersHash.end()) // use hash table to check if available person is in hash table
				teamAvail.push_back(people[i][0]);
		}
	
	if(!teamAvail.empty()){ 
			std::sort(teamAvail.begin(), teamAvail.end());
			return teamAvail.front();
		}


//Find any available person to meet with
	for(long unsigned int i = 0; i < people.size(); i++){ 
			if(name != people[i][0] && people[i][2] == "1")
				teamAvail.push_back(people[i][0]);
		}
		
	if(!teamAvail.empty()){ 
			std::sort(teamAvail.begin(), teamAvail.end());
			return teamAvail.front();
		}

	
}


int main(){
//Test 1
std::string name01 = "Chris";
std::vector<std::string> previousPartners01 = {"0"};
std::vector<std::vector<std::string> > people01(3);

people01[0].push_back("Chris"); people01[1].push_back("Tony"); people01[2].push_back("Ryan");
people01[0].push_back("Bronco"); people01[1].push_back("Explorer"); people01[2].push_back("Focus");
people01[0].push_back("1"); people01[1].push_back("0"); people01[2].push_back("0");



std::cout<<"Test 1 result is: "<<matchFunc(name01, previousPartners01, people01)<<std::endl;


//Test 2
std::string name02 = "Chris";
std::vector<std::string> previousPartners02 = {"0"};
std::vector<std::vector<std::string> > people02(4);

people02[0].push_back("Chris"); people02[1].push_back("Tony"); people02[2].push_back("Ryan"); people02[3].push_back("Ava");
people02[0].push_back("Bronco"); people02[1].push_back("Explorer"); people02[2].push_back("Bronco"); people02[3].push_back("Bronco");
people02[0].push_back("1"); people02[1].push_back("1"); people02[2].push_back("1"); people02[3].push_back("1");

std::cout<<"Test 2 result is: "<<matchFunc(name02, previousPartners02, people02)<<std::endl;




//Test 3
std::string name03 = "Chris";
std::vector<std::string> previousPartners03 = {"Ava"};
std::vector<std::vector<std::string> > people03(4);

people03[0].push_back("Chris"); people03[1].push_back("Tony"); people03[2].push_back("Ryan"); people03[3].push_back("Ava");
people03[0].push_back("Bronco"); people03[1].push_back("Explorer"); people03[2].push_back("Bronco"); people03[3].push_back("Bronco");
people03[0].push_back("1"); people03[1].push_back("0"); people03[2].push_back("1"); people03[3].push_back("1");

std::cout<<"Test 3 result is: "<<matchFunc(name03, previousPartners03, people03)<<std::endl;




//Test 4
std::string name04 = "Chris";
std::vector<std::string> previousPartners04 = {"Ava","Ryan"};
std::vector<std::vector<std::string> > people04(4);

people04[0].push_back("Chris"); people04[1].push_back("Tony"); people04[2].push_back("Ryan"); people04[3].push_back("Ava");
people04[0].push_back("Bronco"); people04[1].push_back("Explorer"); people04[2].push_back("Bronco"); people04[3].push_back("Bronco");
people04[0].push_back("1"); people04[1].push_back("0"); people04[2].push_back("1"); people04[3].push_back("1");

std::cout<<"Test 4 result is: "<<matchFunc(name04, previousPartners04, people04)<<std::endl;


return 0;
}

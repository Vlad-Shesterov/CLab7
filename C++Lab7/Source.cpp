#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
protected:
	string OwnerName;
public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
	void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
		cout << endl;
	}
	void Subscribe() {
		SubscribersCount++;
	}
	void Unsubscribe() {
		if (SubscribersCount > 0)
			SubscribersCount--;
	}
	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}
};

class CookingYouTubeChannel :public YouTubeChannel {
public:
	CookingYouTubeChannel(string name, string ownerName) :YouTubeChannel(name, ownerName) {

	}
	void Practice() {
		cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
	}
};

class GamingYouTubeChannel :public YouTubeChannel {
public:
	GamingYouTubeChannel(string name, string ownerName) :YouTubeChannel(name, ownerName) {

	}
	void Practice() {
		cout << OwnerName << " is plays games, records playthroughs, streams..." << endl;
	}
};

int main()
{
	CookingYouTubeChannel cookingYouTubeChannel("Granny's Kitchen", "Granny");
	GamingYouTubeChannel gamingYouTubeChannel("Son`s Gaming", "Son");

	cookingYouTubeChannel.PublishVideo("Cooking cake.");
	gamingYouTubeChannel.PublishVideo("Play in a game.");

	cookingYouTubeChannel.Subscribe();
	gamingYouTubeChannel.Subscribe();

	cookingYouTubeChannel.GetInfo();
	gamingYouTubeChannel.GetInfo();

	system("pause>0");
}
#include"iostream"
#include"string"
using namespace std;

class MusicPlayer{
    public:
     string playList[100];
     string currentPlayingSong;
     int list;
     
     MusicPlayer(){
        list = 0;
     }

     void addSong(string song){
        playList[list++] = song;
     }

     void removeSong(string remSong){
        int index = -1;
        int length;
        for(int i=0;i<list;i++){
            if(playList[i] == remSong){
                index = i;
            }
        }
        if(index != -1){
            length = playList[index].size();
            playList[index].erase(0,length);
            cout<<remSong<<" deleted successfully"<<endl;
        }
        else{
            cout<<"Song not found"<<endl;
        }
     }

     void playSong(string play){
        int flag = 0;
        for(int i=0;i<list;i++){
            if(playList[i] == play){
                flag = 1;
            }
        }
        if (flag){
            currentPlayingSong = play;
            cout<<"Playing "<<currentPlayingSong<<endl;
        }
        else{
            cout<<"Song not found in your playing list"<<endl;
        }
     }

     void displayPlayList(){
        cout<<"=======Your Playing List=========="<<endl;
       for(int i=0;i<list;i++){
        if(playList[i] == ""){
            playList[i] = "Deleted";
        }
        cout<<playList[i]<<endl;
       }
     }
};

int main(){
    MusicPlayer vlc;
    vlc.addSong("Mast Magan");
    vlc.addSong("Labon ko");
    vlc.addSong("Bakhuda tumhi ho");
    vlc.displayPlayList();
    cout<<"\n";
    vlc.removeSong("Labon ko");
    cout<<"\n";
    vlc.playSong("Mast Magan");
    vlc.displayPlayList();
    cout<<"\n";
    vlc.playSong("bol na");
    vlc.removeSong("kuch nahi");

} 

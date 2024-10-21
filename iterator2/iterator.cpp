#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <ctime>
class Iterator{
    public:
        virtual bool has_next()=0;
        virtual std::string next()=0;
};

class PlaylistIterator : public Iterator{
    const std::vector<std::string> &songs;
    int index;
    public:
        PlaylistIterator(std::vector<std::string> &songlist) : songs(songlist),index(0){}

        bool has_next() override{
            return index<songs.size();
        }

        std::string next() override{
            return songs[index++];
        }
};
class ShufflePlaylistIterator : public Iterator{
    std::vector<std::string> shuffledsong;
    int index;
    public:
        ShufflePlaylistIterator(std::vector<std::string> &songlist) : shuffledsong(songlist),index(0){
             std::random_device rd;
        std::default_random_engine rng(rd());
        std::shuffle(shuffledsong.begin(), shuffledsong.end(), rng);
        }

        bool has_next() override{
            return index<shuffledsong.size();
        }

        std::string next() override{
            return shuffledsong[index++];
        }
};

class Playlist{
    std::vector<std::string> songs;
    public:
        void addSong(const std::string &song){
            songs.push_back(song);
        }

        std::unique_ptr<Iterator> createIterator(){
            return std::make_unique<PlaylistIterator>(songs);
        }

        std::unique_ptr<Iterator> createShuffleIterator(){
            return std::make_unique<ShufflePlaylistIterator>(songs);
        }
};

int main(){
    Playlist playlist;
    playlist.addSong("Dilbara ve");
    playlist.addSong("Sanu ik pal");
    playlist.addSong("Dil de diya");

    std::unique_ptr<Iterator> list = playlist.createIterator();

    std::unique_ptr<Iterator> Shuffledlist = playlist.createShuffleIterator();
    /*
    while(list->has_next()){
        std::cout<<list->next()<<std::endl;
    }
    */

    while(Shuffledlist->has_next()){
        std::cout<<Shuffledlist->next()<<std::endl;
    }

    return 0;
}
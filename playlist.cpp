#include <iostream>
#include <string>
#include "playlist.h"

using namespace std;

Playlist::Playlist(){
   head = nullptr;
   tail = nullptr;
}

Playlist::Playlist(string titles[], int num_titles){
   head = nullptr;
   tail = nullptr;
   Song curr;
   
   for (int i=0; i<num_titles; i++){
      curr.title = titles[i];
      this->Append(curr);
   }
};

void Playlist::Append(Song data){
   NODE* node = new NODE();
   node->next = nullptr;
   node->song = data;
   if(head == nullptr){ 
      head = tail = node;
      node->next = node;    //make it circular
      node->previous = node;
   }
   else {
      tail->next = node;
      node->previous = tail;    //make it doubly linked
      tail = tail->next;    //update tail pointer
      tail->next = head;    //make it circular
      head->previous = tail;
   }
}

void Playlist::Prepend(Song song){
   NODE* node = new NODE();
   node->song = song;
   node->next = head;
   head->previous = node;    //make it doubly linked
   head = node;    //update head pointer
   tail->next = head;    //make it circular
   head->previous = tail;
}

void Playlist::Remove(Song song){
   //removes the first match starting from the end
   if (tail == nullptr){ return; }    //check if list is empty
   NODE *curr = tail;
   while (curr->song.title != song.title){
      curr = curr->previous;    //go backward
      if (curr == tail){ return; }    //node to remove is not present in circular list
   }
   //remove curr
   if (curr == tail){ tail = curr->previous; }    //update tail pointer
   else if (curr == head){ head = curr->next; }    //update head pointer
   
   curr->previous->next = curr->next;    //link preceding node to following node
   curr->next->previous = curr->previous;    //and make it doubly linked
}

void Playlist::InsertAfter(Song old_song, Song new_song){
   NODE *curr = head;
   NODE *new_node = new NODE();
   new_node->song = new_song;
   
   if (head == nullptr){ return; }    //check if list is empty
   
   while (curr->song.title != old_song.title){
      curr = curr->next;
      if (curr == head){ return; }    //check if flight is not in circular list
   }

   if (curr == tail){ tail = new_node; }    //update tail pointer
   
   new_node->next = curr->next;    //connect following node
   new_node->next->previous = new_node;    //make it doubly linked

   curr->next = new_node;    //connect the preceding node
   curr->next->previous = curr;    //make it doubly linked
}

void Playlist::Print(){
   if(head==nullptr){ return; }    //check if empty
   NODE *curr = head;
   do {
      cout << curr->song.title << endl;
      curr = curr->next;
   } while (curr != head);
}

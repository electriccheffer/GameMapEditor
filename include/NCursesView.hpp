#ifndef NCURSESVIEW_HPP
#define NCURSESVIEW_HPP 
#include <ncurses.h>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <array>
 
#define MAX_WINDOWS 3

class Model;

class NCursesView{
	
};


class OptionsView : public NCursesView{};


class DescriptionView : public NCursesView{};

class EditorView : public NCursesView{}; 

#endif

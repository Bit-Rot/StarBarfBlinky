#ifndef COLOR_PALLETTE_H
#define COLOR_PALLETTE_H

class ColorPallette {
	public:
		uint32_t getColor(int i) const {return i < myNumColors ? myColors[i] : 0;};
		int getNumColors() const {return myNumColors;};
		void setNumColors(int numColors) {myNumColors = numColors;};
		uint32_t *getColors() const {return myColors;};
		void setColors(uint32_t *colors) {myColors = colors;};
		uint32_t getRandomColor() const {return myNumColors > 0? myColors[rand() % myNumColors] : 0;};

	private:
		int myNumColors;
		uint32_t *myColors;
};

#endif //COLOR_PALLETTE_H
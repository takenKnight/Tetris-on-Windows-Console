#include <TinField.h>
#include <Keypress.h>
#include <thread>

using namespace std::chrono_literals;

int main()
{
	ScreenBuffer screen;
	Stats stats;
	Field field(stats);
	TinQueue queue;
	TinField TinField(field,queue);
	Keypress key[5]{ 0x25,0x27,0x26,0x28,0x20 };
	while (1)
	{
		std::this_thread::sleep_for(1ms);
		screen.clear();
		TinField.setSpeed(stats.getLevel());

		TinField.move(key[0].once(), { -1,0 }); //left 
		TinField.move(key[1].once(), { 1,0 });  //right
		TinField.rotate(key[2].once());
		TinField.fastDown(key[3].repeated());
		TinField.forceDown(key[4].once());

		field.draw(screen);
		queue.draw(screen);
		TinField.draw(screen);
		stats.draw(screen);

		if (field.getCompletedLine().size() > 0)
		{
			field.draw(screen);
			screen.render();
			std::this_thread::sleep_for(500ms);
			field.clearCompletedLines();
		}
		screen.render();
	}
}
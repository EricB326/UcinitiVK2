#ifndef APPLICATION_H
#define APPLICATION_H

/* Uciniti engine includes
*/
#include "base.h"
#include "Uciniti/Core/time_step.h"
#include "window.h"
#include "layer_stack.h"

#include "Uciniti/Core/Events/event.h"
#include "Uciniti/Core/Events/application_event.h"

int main(int argc, char** argv);

namespace Uciniti 
{
	/* @brief
	*/
	class UCINITI_API application
	{
	public:
		/***************************************************************/
		// Public Functions
		/***************************************************************/
		/* @brief
		*/
		application();

		/* @brief
		*/
		virtual ~application();
		
		/* @brief
		*/
		void run();

		void on_event(event& a_e);

		void push_layer(layer* a_layer);
		void push_overlay(layer* a_overlay);

		static inline application& get() { return *instance; }
		inline window& get_window() { return *window_context; }

	private:
		bool on_window_resize(window_resize_event& a_e);
		bool on_window_close(window_close_event& a_e);

		void shutdown();

		std::unique_ptr<window> window_context;
		bool is_running = true;
		layer_stack app_layer_stack;
		bool _is_minimized = false;

		time_step _time_step;
		float last_frame_time = 0.0f;

		static application* instance;
	};

	/* @brief To be defined by CLIENT.
	*/
	application* create_application();
}

#endif // !APPLICATION_H
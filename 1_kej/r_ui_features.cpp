#include "pch.h"

void Visual_Features();
void RPG_Features();
void Jump_Features();
void Visual_Features()
{
	//ImGui::Text("Basic");
	//ImGui::Separator();

	if (ImGui::CollapsingHeader("Basic")) {

		if (ImGui::Checkbox("velometer", &v::mod_velometer.evar->enabled)) {
			float val = (float)v::mod_velometer.evar->enabled;
			v::mod_velometer.SetValue(&val, 1, 0);
		}

		if (v::mod_velometer.evar->arrayValue[0]) {
			ImGui::SameLine();
			static bool editing;
			if (ImGui::Button("modify##01"))
				editing = !editing;


			if (editing) {
				ImGui::Begin("Modify velometer", &editing);

				const ImGuiViewport* viewport = ImGui::GetMainViewport();

				ImGui::SetWindowSize(ImVec2(viewport->Size.x / 3.f, viewport->Size.y / 3.5f), ImGuiCond_FirstUseEver);

				ImGui::PushItemWidth(100);
				ImGui::DragFloat("x", &v::mod_velometer.evar->arrayValue[1], 1.f, 0.f, 1920.f, "%.0f");

				ImGui::PushItemWidth(100);
				ImGui::DragFloat("y", &v::mod_velometer.evar->arrayValue[2], 1.f, 0.f, 1080.f, "%.0f");

				ImGui::PushItemWidth(100);
				ImGui::DragFloat("font scale", &v::mod_velometer.evar->arrayValue[3], 0.25f, 0.f, 10.f, "%.2f");
				ImGui::End();
			}
		}


		if (ImGui::Checkbox("coordinates", &v::mod_coordinates.evar->enabled)) {
			float val = (float)v::mod_coordinates.evar->enabled;
			v::mod_coordinates.SetValue(&val, 1, 0);

		}if (v::mod_coordinates.evar->arrayValue[0]) {
			ImGui::SameLine();
			static bool editing;
			if (ImGui::Button("modify##02"))
				editing = !editing;


			if (editing) {
				ImGui::Begin("Modify Coordinates", &editing);

				const ImGuiViewport* viewport = ImGui::GetMainViewport();

				ImGui::SetWindowSize(ImVec2(viewport->Size.x / 3.f, viewport->Size.y / 3.5f), ImGuiCond_FirstUseEver);

				ImGui::PushItemWidth(100);
				ImGui::DragFloat("x", &v::mod_coordinates.evar->arrayValue[1], 1.f, 0.f, 1920.f, "%.0f");

				ImGui::PushItemWidth(100);
				ImGui::DragFloat("y", &v::mod_coordinates.evar->arrayValue[2], 1.f, 0.f, 1080.f, "%.0f");

				ImGui::PushItemWidth(100);
				ImGui::DragFloat("font scale", &v::mod_coordinates.evar->arrayValue[3], 0.25f, 0.f, 10.f, "%.2f");
				ImGui::End();
			}
		}
	}
	if (ImGui::CollapsingHeader("Anglehelper")) {

		ImGui::Text("\t"); ImGui::SameLine();
		ImGui::BeginGroup();

		if (ImGui::CollapsingHeader("Main")) {
			if (ImGui::Checkbox("enable HUD", &v::mod_anglehelper.evar->enabled)) {
				float val = (float)v::mod_anglehelper.evar->enabled;
				v::mod_anglehelper.SetValue(&val, 1, 0);
			}
			if (v::mod_anglehelper.evar->arrayValue[0]) {
				ImGui::SameLine();
				static bool editing;
				if (ImGui::Button("modify##04"))
					editing = !editing;


				if (editing) {
					ImGui::Begin("Modify AH HUD", &editing);

					const ImGuiViewport* viewport = ImGui::GetMainViewport();

					ImGui::SetWindowSize(ImVec2(viewport->Size.x / 3.f, viewport->Size.y / 3.5f), ImGuiCond_FirstUseEver);

					ImGui::PushItemWidth(100);
					ImGui::DragFloat("y", &v::mod_anglehelper.evar->arrayValue[1], 1.f, 0.f, 1080.f, "%.0f");

					ImGui::PushItemWidth(100);
					ImGui::DragFloat("height", &v::mod_anglehelper.evar->arrayValue[2], 1.f, 0.f, 1080.f, "%.0f");

					ImGui::PushItemWidth(100);
					ImGui::DragFloat("fovscale", &v::mod_anglehelper.evar->arrayValue[3], 0.25f, 0.f, 10.f, "%.2f");
					ImGui::End();
				}
			}
		}

		ImGui::EndGroup();

		ImGui::Text("\t"); ImGui::SameLine();
		ImGui::BeginGroup();
		if (ImGui::CollapsingHeader("Transfer Zone")) {
			if (ImGui::Checkbox("horizontal bar", &v::mod_fps_transferz.evar->enabled)) {
				float val = (float)v::mod_fps_transferz.evar->enabled;
				v::mod_fps_transferz.SetValue(&val, 1, 0);
			}

			if(v::mod_fps_transferz.evar->arrayValue[0]){
				ImGui::SameLine();
				static bool editing;
				if (ImGui::Button("modify##03"))
					editing = !editing;


				if (editing) {
					ImGui::Begin("Modify Transfer Zone UI", &editing);

					const ImGuiViewport* viewport = ImGui::GetMainViewport();

					ImGui::SetWindowSize(ImVec2(viewport->Size.x / 3.f, viewport->Size.y / 3.5f), ImGuiCond_FirstUseEver);

					ImGui::PushItemWidth(100);
					ImGui::DragFloat("y", &v::mod_fps_transferz.evar->arrayValue[1], 1.f, 0.f, 1080.f, "%.0f");

					ImGui::PushItemWidth(100);
					ImGui::DragFloat("height", &v::mod_fps_transferz.evar->arrayValue[2], 1.f, 0.f, 1080.f, "%.0f");

					ImGui::PushItemWidth(100);
					ImGui::DragFloat("fovscale", &v::mod_fps_transferz.evar->arrayValue[3], 0.25f, 0.f, 10.f, "%.2f");
					ImGui::End();
				}
			}
			static bool dummy = v::mod_fps_transferz.evar->arrayValue[4] != NULL;
			if (ImGui::Checkbox("Change crosshair color", &dummy)) {
				v::mod_fps_transferz.evar->arrayValue[4] = (float)dummy;
			} ImGui::SameLine(); r::MetricsHelpMarker("Crosshair color changes to green when you should strafe change and changes to red if you go past a transfer zone");
		}
		ImGui::EndGroup();
		ImGui::Text("\t"); ImGui::SameLine();
		ImGui::BeginGroup();
		if (ImGui::CollapsingHeader("Miscellaneous")) {
			if (ImGui::Checkbox("Velocity direction", &v::mod_veldirection.evar->enabled)) {
				v::mod_veldirection.SetValue(v::mod_veldirection.isEnabled());

			} ImGui::SameLine(); r::MetricsHelpMarker("Draw a line underneath the player indicating the velocity direction");

			if (ImGui::Checkbox("Show world axes", &v::mod_show_worldaxes.evar->enabled)) {
				v::mod_show_worldaxes.SetValue(v::mod_show_worldaxes.isEnabled());

			} ImGui::SameLine(); r::MetricsHelpMarker("Draw the XY world axes underneath the player to give an understanding of current angles (useful with angled jumps)");

			if (!v::mod_show_worldaxes.isEnabled())
				ImGui::BeginDisabled();

			ImGui::Text("\t"); ImGui::SameLine();

			if (ImGui::Checkbox("Include optimal angle", &v::mod_worldaxes_opt.evar->enabled)) {
				v::mod_worldaxes_opt.SetValue(v::mod_worldaxes_opt.isEnabled());

			}

			if (!v::mod_show_worldaxes.isEnabled())
				ImGui::EndDisabled();


			if (ImGui::Checkbox("Curve Speed", &v::mod_curve_speed.evar->enabled)) {
				v::mod_curve_speed.SetValue(v::mod_curve_speed.isEnabled());

			} ImGui::SameLine(); r::MetricsHelpMarker("draw the difference in angle every 50 snapshots");

		}	
		ImGui::EndGroup();
	}
	if (ImGui::CollapsingHeader("Crosshair")) {
		//ImGui::Text("crosshair color"); ImGui::SameLine();
		ImGui::ColorEdit3("crosshair color", v::mod_crosshair.evar->vecValue, ImGuiColorEditFlags_NoInputs);
		ImGui::PushItemWidth(70);
		ImGui::SliderFloat("Min Alpha", &v::mod_crosshair.evar->vecValue[3], 0, 1, "%.2f"); ImGui::SameLine();  r::MetricsHelpMarker("Minimum amount of transparency the crosshair can have");
	}
	if (ImGui::CollapsingHeader("World")) {
		//ImGui::Text("Advanced");
		//ImGui::Separator();

		if (ImGui::Checkbox("bounceable surface", &v::mod_bounceable_surf.evar->enabled)) {
			v::mod_bounceable_surf.SetValue(v::mod_bounceable_surf.isEnabled());
		} ImGui::SameLine(); r::MetricsHelpMarker("notify if you are looking at a bounce");
		if (ImGui::Checkbox("elevatable surface", &v::mod_elevatable_surf.evar->enabled)) {
			v::mod_elevatable_surf.SetValue(v::mod_elevatable_surf.isEnabled());
		} ImGui::SameLine(); r::MetricsHelpMarker("notify if you are looking at an elevatable wall");
	}
}
void RPG_Features()
{
	static int rpg_mode;
	static const char* items[] = { "default", "switch", "sustain" };
	ImGui::PushItemWidth(150);

	if(ImGui::Combo("Mode", &rpg_mode, items, 3))
		v::mod_rpg_mode.SetValue(items[rpg_mode]);

	if (ImGui::Checkbox("RPG timing", &v::mod_rpg_timing.evar->enabled)) {
		v::mod_rpg_timing.SetValue(v::mod_rpg_timing.isEnabled());
	} ImGui::SameLine(); r::MetricsHelpMarker("prints the rpg timing (calculated in command time)");

	if (ImGui::Checkbox("RPG angle", &v::mod_rpg_angle.evar->enabled)) {
		v::mod_rpg_angle.SetValue(v::mod_rpg_angle.isEnabled());
	} ImGui::SameLine(); r::MetricsHelpMarker("prints the player's pitch angle when they shoot the rpg (and they also bounce)");
}
void Jump_Features()
{
	//ImGui::Text("Utilities");
	//ImGui::Separator();

	if (ImGui::CollapsingHeader("Utilities")) {

		if (ImGui::Checkbox("hit analyzer", &v::mod_hitanalyzer.evar->enabled)) {
			v::mod_hitanalyzer.SetValue(v::mod_hitanalyzer.evar->enabled);
		} ImGui::SameLine(); r::MetricsHelpMarker("print the difference in velocity before and after bounce");
		if (ImGui::Checkbox("jump analyzer", &v::mod_jumpanalyzer.evar->enabled)) {
			v::mod_jumpanalyzer.SetValue(v::mod_jumpanalyzer.evar->enabled);
		} ImGui::SameLine(); r::MetricsHelpMarker("print the jump velocity and velocity on bounce hit");
	}
	//ImGui::Text("Movement");
	//ImGui::Separator();

	if (ImGui::CollapsingHeader("Movement")) {

		if (ImGui::Checkbox("fixed fps", &v::mod_pmove_fixed.evar->enabled)) {
			v::mod_pmove_fixed.SetValue(v::mod_pmove_fixed.isEnabled());
		} ImGui::SameLine(); r::MetricsHelpMarker("simulates a stable fps for a more consistent experience\nnote: this feature can make a big difference in your codjumping skill\nnote 2: this feature will bug out demos, so don't record demos while this is enabled!");

		if (ImGui::Checkbox("Bunnyhopping", &v::mod_bhop.evar->enabled)) {
			v::mod_bhop.SetValue(v::mod_bhop.evar->enabled);
			cg::Mod_EditMemory(false);

		}

		//////////////////////////////////////////
		if (!v::mod_bhop.isEnabled())
			ImGui::BeginDisabled(true);

		ImGui::Text("\t");
		ImGui::SameLine();
		if (ImGui::Checkbox("No Delay", &v::mod_bhop_nodelay.evar->enabled)) {
			v::mod_bhop_nodelay.SetValue(v::mod_bhop_nodelay.evar->enabled);
			cg::Mod_EditMemory(false);

		}

		if (!v::mod_bhop.isEnabled())
			ImGui::EndDisabled();
	}
	//////////////////////////////////////////

	//if (ImGui::CollapsingHeader("Jump view")) {
	//	static bool isOpen = false;


	//	ImGui::Text("\t");
	//	ImGui::SameLine();
	//	if (ImGui::Button("open editor")) {
	//		isOpen = !isOpen;
	//		dvar_s* g_gravity = Dvar_FindMalleableVar("g_gravity");

	//		if (g_gravity) {
	//			g_gravity->current.value = (isOpen == true) ? 0 : 800;
	//		}
	//	}

	//	r::R_JumpView(isOpen);

	//}


}

/*

void    ImGui::SetTabItemClosed(const char* label)
{
	ImGuiContext& g = *GImGui;
	bool is_within_manual_tab_bar = g.CurrentTabBar && !(g.CurrentTabBar->Flags & ImGuiTabBarFlags_DockNode);
	if (is_within_manual_tab_bar)
	{
		ImGuiTabBar* tab_bar = g.CurrentTabBar;
		ImGuiID tab_id = TabBarCalcTabID(tab_bar, label);
		if (ImGuiTabItem* tab = TabBarFindTabByID(tab_bar, tab_id))
			tab->WantClose = true; // Will be processed by next call to TabBarLayout()
	}
}

void MakeTabVisible(const char* window_name)
{
	ImGuiWindow* window = ImGui::FindWindowByName(window_name);
	if (window == NULL || window->DockNode == NULL || window->DockNode->TabBar == NULL)
		return;
	window->DockNode->TabBar->NextSelectedTabId = window->ID;;
}

if (ImGui::Button("Log"))
   MakeTabVisible("Example: Log");
if (ImGui::Button("Console"))
   MakeTabVisible("Example: Console");

*/
void r::R_Features(bool& wantsEditor)
{


	static bool jumping_tab;
	if (ImGui::BeginTabBar("##tabs", ImGuiTabBarFlags_None)) {
		if (ImGui::BeginTabItem("Visual")) {
			jumping_tab = false;
			Visual_Features();
			ImGui::EndTabItem();

		}if (ImGui::BeginTabItem("RPG")) {
			jumping_tab = false;
			RPG_Features();
			ImGui::EndTabItem();

		}if (ImGui::BeginTabItem("Jumping")) {
			if(!jumping_tab)
				jumping_tab = !jumping_tab;
			ImGui::EndTabItem();
		}
		ImGui::SameLine();
		if (ImGui::Button("Jump Preview")) {
			jumping_tab = false;
			dvar_s* g_gravity = Dvar_FindMalleableVar("g_gravity");

			if (g_gravity) {
				g_gravity->current.value = 0;
			}
			wantsEditor = !wantsEditor;
		}
		if(jumping_tab)
			Jump_Features();


	}
	ImGui::EndTabBar();
}

void r::R_JumpView_Help()
{
	ImGui::NewLine();
	ImGui::Text("Keybinds");
	ImGui::Separator();

	//ImGui::ShowDemoWindow();

	ImGui::BulletText("[SPACEBAR]	 - Toggle free mode");
	ImGui::BulletText("[P]			- Toggle playback");
	ImGui::BulletText("[C]			- Move to current frame");
	ImGui::BulletText("[->]		   - Next Frame");
	ImGui::BulletText("[<-]		   - Previous Frame");
	ImGui::BulletText("[F]		    - Toggle Force Position");
	ImGui::BulletText("[M]		    - Toggle Menu Drawing");

}
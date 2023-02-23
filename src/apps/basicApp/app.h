#pragma once

#include <crl-basic/gui/application.h>
#include <crl-basic/gui/plots.h>
#include <crl-basic/utils/logger.h>

namespace basicApp {

class App : public crl::gui::ShadowApplication {
public:
    App() : crl::gui::ShadowApplication("Basic 3D App"), rtPlot("Real-time Plot Example", "x", "y", 1000, 500) {
        showPlots = true;
        model.scale *= 0.1;

        // real-time plot line specifications
        rtPlot.addLineSpec({"sin(x)", [](const auto& d) { return (float)d[0]; }});
        rtPlot.addLineSpec({"cos(x)", [](const auto& d) { return (float)d[1]; }});
    }

    void process() override {
        static int i = 0;
        crl::Logger::consolePrint("Process is running...\n");

        // real-time plot data
        crl::dVector rtPlotData(2);
        rtPlotData << std::sin(i * 0.01), std::cos(i * 0.01);
        rtPlot.addData((float)i++, rtPlotData);
    }

    void drawShadowCastingObjects(const crl::gui::Shader& shader) override {
        model.draw(shader, crl::gui::toV3D(selectedColor), 1.f, false);
    }

    void drawObjectsWithoutShadows(const crl::gui::Shader& shader) override {
        if (model.selected || model.highlighted)
            model.draw(shader, crl::gui::toV3D(selectedColor), 1.f, false);
        else
            model.draw(shader, crl::gui::toV3D(normalColor), 1.f, true);
    }

    void drawImGui() override {
        //ImGui
        crl::gui::ShadowApplication::drawImGui();

        ImGui::Begin("Main Menu");

        if (!model.selected)
            ImGui::ColorPicker3("Color", &normalColor[0]);

        ImGui::End();

        //Widget
        if (model.selected) {
            ImGui::Begin("Transform Widget");
            ImGuizmo::BeginFrame();
            crl::gui::setTransformFromWidgets(camera.getViewMatrix(), camera.getProjectionMatrix(), model.scale, model.orientation, model.position);
            ImGui::End();
        }
    }

    void drawImPlot() override {
        crl::gui::ShadowApplication::drawImPlot();
        ImGui::Begin("Plots");
        rtPlot.draw();
        ImGui::End();
    }

    bool mouseMove(double xpos, double ypos) override {
        if (mouseState.dragging == false) {
            crl::P3D rayOrigin;
            crl::V3D rayDirection;
            camera.getRayFromScreenCoordinates(xpos, ypos, rayOrigin, rayDirection);
            model.highlighted = model.hitByRay(rayOrigin, rayDirection);
        }
        return crl::gui::ShadowApplication::mouseMove(xpos, ypos);
    }

    bool mouseButtonPressed(int button, int mods) override {
        if (button == GLFW_MOUSE_BUTTON_LEFT)
            model.selected = model.highlighted;
        return true;
    }

    bool drop(int count, const char** fileNames) override {
        model = crl::gui::Model(fileNames[count - 1]);
        return true;
    }

public:
    crl::gui::Model model = crl::gui::Model(CRL_DATA_FOLDER "/meshes/nanosuit.obj");
    float selectedColor[3] = {0.8f, 0.2f, 0.1f};
    float normalColor[3] = {0.2f, 0.5f, 0.7f};

    // real-time plot example
    crl::gui::RealTimeLinePlot2D<crl::dVector> rtPlot;
};
}  // namespace basicApp
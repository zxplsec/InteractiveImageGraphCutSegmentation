/*
Copyright (C) 2010 David Doria, daviddoria@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef vtkGraphCutInteractorStyle_H
#define vtkGraphCutInteractorStyle_H

#include <vtkInteractorStyleImage.h> // superclass
#include <vtkSmartPointer.h>

#include "ImageGraphCut.h"

class vtkImageActor;
class vtkImageTracerWidget;
class vtkImageData;

class vtkGraphCutInteractorStyle : public vtkInteractorStyleImage
{
public:
  static vtkGraphCutInteractorStyle* New();
  vtkTypeMacro(vtkGraphCutInteractorStyle, vtkInteractorStyleImage);

  vtkGraphCutInteractorStyle();

  int GetSelectionType();
  enum SELECTION {FOREGROUND, BACKGROUND};

  void SetInteractionModeToForeground();
  void SetInteractionModeToBackground();

  vtkPolyData* GetForegroundSelection();
  vtkPolyData* GetBackgroundSelection();

  void ClearSelections();

  void InitializeTracer(vtkImageActor* imageActor);

private:
  void Refresh();
  void CatchWidgetEvent(vtkObject* caller, long unsigned int eventId, void* callData);

  int SelectionType;

  vtkSmartPointer<vtkImageTracerWidget> Tracer;
  vtkSmartPointer<vtkImageData> ResultImage;
  vtkSmartPointer<vtkPolyData> ForegroundSelection;
  vtkSmartPointer<vtkPolyData> BackgroundSelection;

  vtkSmartPointer<vtkPolyDataMapper> BackgroundSelectionMapper;
  vtkSmartPointer<vtkPolyDataMapper> ForegroundSelectionMapper;

  vtkSmartPointer<vtkActor> BackgroundSelectionActor;
  vtkSmartPointer<vtkActor> ForegroundSelectionActor;

};

#endif
// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_LINUX_PUBLIC_FLUTTER_LINUX_FL_VIEW_WIDGET_H_
#define FLUTTER_SHELL_PLATFORM_LINUX_PUBLIC_FLUTTER_LINUX_FL_VIEW_WIDGET_H_

#if !defined(__FLUTTER_LINUX_INSIDE__) && !defined(FLUTTER_LINUX_COMPILATION)
#error "Only <flutter_linux/flutter_linux.h> can be included directly."
#endif

#include <gmodule.h>
#include <gtk/gtk.h>

#include "fl_dart_project.h"
#include "fl_engine.h"
#include "fl_view.h"

G_BEGIN_DECLS

G_MODULE_EXPORT
G_DECLARE_FINAL_TYPE(FlViewWidget, fl_view_widget, FL, VIEW_WIDGET, GtkBox)

/**
 * FlViewWidget:
 *
 * #FlViewWidget is a GTK widget that is capable of displaying a Flutter application.
 *
 * The following example shows how to set up a view in a GTK application:
 * |[<!-- language="C" -->
 *   FlDartProject *project = fl_dart_project_new ();
 *   FlView *view = fl_view_widget_new (project);
 *   gtk_widget_show (GTK_WIDGET (view));
 *   gtk_container_add (GTK_CONTAINER (parent), view);
 *
 *   FlBinaryMessenger *messenger =
 *     fl_engine_get_binary_messenger (fl_view_get_engine (view));
 *   setup_channels_or_plugins (messenger);
 * ]|
 */

/**
 * fl_view_new:
 * @project: The project to show.
 *
 * Creates a widget to show a Flutter application.
 *
 * Returns: a new #FlView.
 */
FlView* fl_view_widget_new(FlDartProject* project);

/**
 * fl_view_new_for_engine:
 * @engine: an #FlEngine.
 *
 * Creates a widget to show a window in a Flutter application.
 * The engine must be not be headless.
 *
 * Returns: a new #FlView.
 */
FlView* fl_view_widget_new_for_engine(FlEngine* engine);

G_END_DECLS

#endif  // FLUTTER_SHELL_PLATFORM_LINUX_PUBLIC_FLUTTER_LINUX_FL_VIEW_WIDGET_H_

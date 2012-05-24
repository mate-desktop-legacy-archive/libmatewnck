


#include <libmatewnck/libmatewnck.h>

/* enumerations from "pager.h" */
static const GEnumValue _matewnck_pager_display_mode_values[] = {
  { MATEWNCK_PAGER_DISPLAY_NAME, "MATEWNCK_PAGER_DISPLAY_NAME", "name" },
  { MATEWNCK_PAGER_DISPLAY_CONTENT, "MATEWNCK_PAGER_DISPLAY_CONTENT", "content" },
  { 0, NULL, NULL }
};

GType
matewnck_pager_display_mode_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckPagerDisplayMode", _matewnck_pager_display_mode_values);

  return type;
}

static const GEnumValue _matewnck_pager_layout_policy_values[] = {
  { MATEWNCK_PAGER_LAYOUT_POLICY_AUTOMATIC, "MATEWNCK_PAGER_LAYOUT_POLICY_AUTOMATIC", "automatic" },
  { MATEWNCK_PAGER_LAYOUT_POLICY_WIDTH_FOR_HEIGHT, "MATEWNCK_PAGER_LAYOUT_POLICY_WIDTH_FOR_HEIGHT", "width-for-height" },
  { MATEWNCK_PAGER_LAYOUT_POLICY_HEIGHT_FOR_WIDTH, "MATEWNCK_PAGER_LAYOUT_POLICY_HEIGHT_FOR_WIDTH", "height-for-width" },
  { 0, NULL, NULL }
};

GType
matewnck_pager_layout_policy_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckPagerLayoutPolicy", _matewnck_pager_layout_policy_values);

  return type;
}


/* enumerations from "screen.h" */
static const GEnumValue _matewnck_motion_direction_values[] = {
  { MATEWNCK_MOTION_UP, "MATEWNCK_MOTION_UP", "up" },
  { MATEWNCK_MOTION_DOWN, "MATEWNCK_MOTION_DOWN", "down" },
  { MATEWNCK_MOTION_LEFT, "MATEWNCK_MOTION_LEFT", "left" },
  { MATEWNCK_MOTION_RIGHT, "MATEWNCK_MOTION_RIGHT", "right" },
  { 0, NULL, NULL }
};

GType
matewnck_motion_direction_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckMotionDirection", _matewnck_motion_direction_values);

  return type;
}

static const GEnumValue __matewncklayoutorientation___matewnck_layout_orientation_values[] = {
  { MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL, "MATEWNCK_LAYOUT_ORIENTATION_HORIZONTAL", "horizontal" },
  { MATEWNCK_LAYOUT_ORIENTATION_VERTICAL, "MATEWNCK_LAYOUT_ORIENTATION_VERTICAL", "vertical" },
  { 0, NULL, NULL }
};

GType
_matewncklayoutorientation___matewnck_layout_orientation_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("_MateWnckLayoutOrientation", __matewncklayoutorientation___matewnck_layout_orientation_values);

  return type;
}

static const GEnumValue __matewncklayoutcorner___matewnck_layout_corner_values[] = {
  { MATEWNCK_LAYOUT_CORNER_TOPLEFT, "MATEWNCK_LAYOUT_CORNER_TOPLEFT", "topleft" },
  { MATEWNCK_LAYOUT_CORNER_TOPRIGHT, "MATEWNCK_LAYOUT_CORNER_TOPRIGHT", "topright" },
  { MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT, "MATEWNCK_LAYOUT_CORNER_BOTTOMRIGHT", "bottomright" },
  { MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT, "MATEWNCK_LAYOUT_CORNER_BOTTOMLEFT", "bottomleft" },
  { 0, NULL, NULL }
};

GType
_matewncklayoutcorner___matewnck_layout_corner_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("_MateWnckLayoutCorner", __matewncklayoutcorner___matewnck_layout_corner_values);

  return type;
}


/* enumerations from "tasklist.h" */
static const GEnumValue _matewnck_tasklist_grouping_type_values[] = {
  { MATEWNCK_TASKLIST_NEVER_GROUP, "MATEWNCK_TASKLIST_NEVER_GROUP", "never-group" },
  { MATEWNCK_TASKLIST_AUTO_GROUP, "MATEWNCK_TASKLIST_AUTO_GROUP", "auto-group" },
  { MATEWNCK_TASKLIST_ALWAYS_GROUP, "MATEWNCK_TASKLIST_ALWAYS_GROUP", "always-group" },
  { 0, NULL, NULL }
};

GType
matewnck_tasklist_grouping_type_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckTasklistGroupingType", _matewnck_tasklist_grouping_type_values);

  return type;
}


/* enumerations from "util.h" */
static const GEnumValue _matewnck_client_type_values[] = {
  { MATEWNCK_CLIENT_TYPE_APPLICATION, "MATEWNCK_CLIENT_TYPE_APPLICATION", "application" },
  { MATEWNCK_CLIENT_TYPE_PAGER, "MATEWNCK_CLIENT_TYPE_PAGER", "pager" },
  { 0, NULL, NULL }
};

GType
matewnck_client_type_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckClientType", _matewnck_client_type_values);

  return type;
}


/* enumerations from "window.h" */
static const GFlagsValue _matewnck_window_state_values[] = {
  { MATEWNCK_WINDOW_STATE_MINIMIZED, "MATEWNCK_WINDOW_STATE_MINIMIZED", "minimized" },
  { MATEWNCK_WINDOW_STATE_MAXIMIZED_HORIZONTALLY, "MATEWNCK_WINDOW_STATE_MAXIMIZED_HORIZONTALLY", "maximized-horizontally" },
  { MATEWNCK_WINDOW_STATE_MAXIMIZED_VERTICALLY, "MATEWNCK_WINDOW_STATE_MAXIMIZED_VERTICALLY", "maximized-vertically" },
  { MATEWNCK_WINDOW_STATE_SHADED, "MATEWNCK_WINDOW_STATE_SHADED", "shaded" },
  { MATEWNCK_WINDOW_STATE_SKIP_PAGER, "MATEWNCK_WINDOW_STATE_SKIP_PAGER", "skip-pager" },
  { MATEWNCK_WINDOW_STATE_SKIP_TASKLIST, "MATEWNCK_WINDOW_STATE_SKIP_TASKLIST", "skip-tasklist" },
  { MATEWNCK_WINDOW_STATE_STICKY, "MATEWNCK_WINDOW_STATE_STICKY", "sticky" },
  { MATEWNCK_WINDOW_STATE_HIDDEN, "MATEWNCK_WINDOW_STATE_HIDDEN", "hidden" },
  { MATEWNCK_WINDOW_STATE_FULLSCREEN, "MATEWNCK_WINDOW_STATE_FULLSCREEN", "fullscreen" },
  { MATEWNCK_WINDOW_STATE_DEMANDS_ATTENTION, "MATEWNCK_WINDOW_STATE_DEMANDS_ATTENTION", "demands-attention" },
  { MATEWNCK_WINDOW_STATE_URGENT, "MATEWNCK_WINDOW_STATE_URGENT", "urgent" },
  { MATEWNCK_WINDOW_STATE_ABOVE, "MATEWNCK_WINDOW_STATE_ABOVE", "above" },
  { MATEWNCK_WINDOW_STATE_BELOW, "MATEWNCK_WINDOW_STATE_BELOW", "below" },
  { 0, NULL, NULL }
};

GType
matewnck_window_state_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_flags_register_static ("MateWnckWindowState", _matewnck_window_state_values);

  return type;
}

static const GFlagsValue _matewnck_window_actions_values[] = {
  { MATEWNCK_WINDOW_ACTION_MOVE, "MATEWNCK_WINDOW_ACTION_MOVE", "move" },
  { MATEWNCK_WINDOW_ACTION_RESIZE, "MATEWNCK_WINDOW_ACTION_RESIZE", "resize" },
  { MATEWNCK_WINDOW_ACTION_SHADE, "MATEWNCK_WINDOW_ACTION_SHADE", "shade" },
  { MATEWNCK_WINDOW_ACTION_STICK, "MATEWNCK_WINDOW_ACTION_STICK", "stick" },
  { MATEWNCK_WINDOW_ACTION_MAXIMIZE_HORIZONTALLY, "MATEWNCK_WINDOW_ACTION_MAXIMIZE_HORIZONTALLY", "maximize-horizontally" },
  { MATEWNCK_WINDOW_ACTION_MAXIMIZE_VERTICALLY, "MATEWNCK_WINDOW_ACTION_MAXIMIZE_VERTICALLY", "maximize-vertically" },
  { MATEWNCK_WINDOW_ACTION_CHANGE_WORKSPACE, "MATEWNCK_WINDOW_ACTION_CHANGE_WORKSPACE", "change-workspace" },
  { MATEWNCK_WINDOW_ACTION_CLOSE, "MATEWNCK_WINDOW_ACTION_CLOSE", "close" },
  { MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_HORIZONTALLY, "MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_HORIZONTALLY", "unmaximize-horizontally" },
  { MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_VERTICALLY, "MATEWNCK_WINDOW_ACTION_UNMAXIMIZE_VERTICALLY", "unmaximize-vertically" },
  { MATEWNCK_WINDOW_ACTION_UNSHADE, "MATEWNCK_WINDOW_ACTION_UNSHADE", "unshade" },
  { MATEWNCK_WINDOW_ACTION_UNSTICK, "MATEWNCK_WINDOW_ACTION_UNSTICK", "unstick" },
  { MATEWNCK_WINDOW_ACTION_MINIMIZE, "MATEWNCK_WINDOW_ACTION_MINIMIZE", "minimize" },
  { MATEWNCK_WINDOW_ACTION_UNMINIMIZE, "MATEWNCK_WINDOW_ACTION_UNMINIMIZE", "unminimize" },
  { MATEWNCK_WINDOW_ACTION_MAXIMIZE, "MATEWNCK_WINDOW_ACTION_MAXIMIZE", "maximize" },
  { MATEWNCK_WINDOW_ACTION_UNMAXIMIZE, "MATEWNCK_WINDOW_ACTION_UNMAXIMIZE", "unmaximize" },
  { MATEWNCK_WINDOW_ACTION_FULLSCREEN, "MATEWNCK_WINDOW_ACTION_FULLSCREEN", "fullscreen" },
  { MATEWNCK_WINDOW_ACTION_ABOVE, "MATEWNCK_WINDOW_ACTION_ABOVE", "above" },
  { MATEWNCK_WINDOW_ACTION_BELOW, "MATEWNCK_WINDOW_ACTION_BELOW", "below" },
  { 0, NULL, NULL }
};

GType
matewnck_window_actions_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_flags_register_static ("MateWnckWindowActions", _matewnck_window_actions_values);

  return type;
}

static const GEnumValue _matewnck_window_type_values[] = {
  { MATEWNCK_WINDOW_NORMAL, "MATEWNCK_WINDOW_NORMAL", "normal" },
  { MATEWNCK_WINDOW_DESKTOP, "MATEWNCK_WINDOW_DESKTOP", "desktop" },
  { MATEWNCK_WINDOW_DOCK, "MATEWNCK_WINDOW_DOCK", "dock" },
  { MATEWNCK_WINDOW_DIALOG, "MATEWNCK_WINDOW_DIALOG", "dialog" },
  { MATEWNCK_WINDOW_TOOLBAR, "MATEWNCK_WINDOW_TOOLBAR", "toolbar" },
  { MATEWNCK_WINDOW_MENU, "MATEWNCK_WINDOW_MENU", "menu" },
  { MATEWNCK_WINDOW_UTILITY, "MATEWNCK_WINDOW_UTILITY", "utility" },
  { MATEWNCK_WINDOW_SPLASHSCREEN, "MATEWNCK_WINDOW_SPLASHSCREEN", "splashscreen" },
  { 0, NULL, NULL }
};

GType
matewnck_window_type_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckWindowType", _matewnck_window_type_values);

  return type;
}

static const GEnumValue _matewnck_window_gravity_values[] = {
  { MATEWNCK_WINDOW_GRAVITY_CURRENT, "MATEWNCK_WINDOW_GRAVITY_CURRENT", "current" },
  { MATEWNCK_WINDOW_GRAVITY_NORTHWEST, "MATEWNCK_WINDOW_GRAVITY_NORTHWEST", "northwest" },
  { MATEWNCK_WINDOW_GRAVITY_NORTH, "MATEWNCK_WINDOW_GRAVITY_NORTH", "north" },
  { MATEWNCK_WINDOW_GRAVITY_NORTHEAST, "MATEWNCK_WINDOW_GRAVITY_NORTHEAST", "northeast" },
  { MATEWNCK_WINDOW_GRAVITY_WEST, "MATEWNCK_WINDOW_GRAVITY_WEST", "west" },
  { MATEWNCK_WINDOW_GRAVITY_CENTER, "MATEWNCK_WINDOW_GRAVITY_CENTER", "center" },
  { MATEWNCK_WINDOW_GRAVITY_EAST, "MATEWNCK_WINDOW_GRAVITY_EAST", "east" },
  { MATEWNCK_WINDOW_GRAVITY_SOUTHWEST, "MATEWNCK_WINDOW_GRAVITY_SOUTHWEST", "southwest" },
  { MATEWNCK_WINDOW_GRAVITY_SOUTH, "MATEWNCK_WINDOW_GRAVITY_SOUTH", "south" },
  { MATEWNCK_WINDOW_GRAVITY_SOUTHEAST, "MATEWNCK_WINDOW_GRAVITY_SOUTHEAST", "southeast" },
  { MATEWNCK_WINDOW_GRAVITY_STATIC, "MATEWNCK_WINDOW_GRAVITY_STATIC", "static" },
  { 0, NULL, NULL }
};

GType
matewnck_window_gravity_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_enum_register_static ("MateWnckWindowGravity", _matewnck_window_gravity_values);

  return type;
}

static const GFlagsValue _matewnck_window_move_resize_mask_values[] = {
  { MATEWNCK_WINDOW_CHANGE_X, "MATEWNCK_WINDOW_CHANGE_X", "x" },
  { MATEWNCK_WINDOW_CHANGE_Y, "MATEWNCK_WINDOW_CHANGE_Y", "y" },
  { MATEWNCK_WINDOW_CHANGE_WIDTH, "MATEWNCK_WINDOW_CHANGE_WIDTH", "width" },
  { MATEWNCK_WINDOW_CHANGE_HEIGHT, "MATEWNCK_WINDOW_CHANGE_HEIGHT", "height" },
  { 0, NULL, NULL }
};

GType
matewnck_window_move_resize_mask_get_type (void)
{
  static GType type = 0;

  if (!type)
    type = g_flags_register_static ("MateWnckWindowMoveResizeMask", _matewnck_window_move_resize_mask_values);

  return type;
}





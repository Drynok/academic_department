; $Id: README.txt,v 1.2.6.1 2010/11/07 20:25:39 davereid Exp $

The RealName module allows the admin to choose fields from the user profile
that will be used to add a "realname" element (method) to a user object.
Hook_user is used to automatically add this to any user object that is loaded.

Installation
------------
Standard module installation applies.

Menus
-----
The only menu item is for the settings page.

Settings
--------
The settings page is at Administer >> Config >> User >> Real name.

This is where you choose which user tokens will be used
to create the user's RealName.

Permissions
-----------
There are no new permissions. The settings page is controlled by the
"administer users" permission.

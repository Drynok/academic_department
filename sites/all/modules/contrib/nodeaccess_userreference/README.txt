; $Id: README.txt,v 1.1.2.2.2.2.2.1 2011/01/13 02:42:02 danielb Exp $

Node access user reference README

CONTENTS OF THIS FILE
----------------------

  * Introduction
  * Installation
  * Configuration
  * Usage
  

INTRODUCTION
------------
Maintainer: Daniel Braksator (http://drupal.org/user/134005)

Project page: http://drupal.org/project/nodeaccess_userreference.


INSTALLATION
------------
1. Install User reference from the References project:
   http://drupal.org/project/references
2. Copy nodeaccess_userreference folder to modules directory.
   (Usually 'sites/all/modules')
3. At 'admin/build/modules' enable the Node access user reference module.


CONFIGURATION
-------------
At admin/config/nodeaccess_userreference configure the node author's access
settings.  This feature is provided because an author's default access will be
removed when referenced users are given access.  You can also use other node
access modules to grant access to authors, users by user role or some other
configuration - look at Drupal.org's module list under the module category
'Content access control'.
You will also see an option to change priority, it is best to leave this to 0
unless you are for some reason trying to prevent another node access module
from setting its grants at the same time.


USAGE
-----
Create a User reference field in your content type, on the page where you 
configure the properties of your field, you will also see settings for 
granting access to the referenced user.
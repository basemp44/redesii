#ifndef _IRCPARSEINTERACTIONCOMMANDS_H_
#define  _IRCPARSENTERACTIONCOMMANDS_H_


long IRCUserParse_CommandQuery(char *in);

/********************************************************************
/NAMES
 
Return users on current channel
********************************************************************/

/********************************************************************
/HELP command
 
Changes your online nick name. Alerts others to the
change of your nick
********************************************************************/
long IRCUserParse_Help(char *in, char **command);

/********************************************************************
/LIST search string
 
If you don't include a search string, the default is to
send you the entire unfiltered list of channels. Below
are the options you can use, and what channels LIST
will return when you use them.
 
 >number - List channels with more than <number> people.
 <number - List channels with less than <number> people.
 C>number - List channels created between now and <number> minutes ago.
 C<number - List channels created earlier than <number> minutes ago.
 T>number - List channels whose topics are older than <number>
 T<number - List channels whose topics are newer than <number> minutes.
 *mask* - List channels that match *mask*
 !*mask* - List channels that do not match *mask*
********************************************************************/
long IRCUserParse_List(char *in, char **searchstring);

/********************************************************************
/JOIN channel1 channel2, ...
 
Allows you to join channels. Using the /join
#channel1,#channel2,#channel3 will allow you to join
more than one channel at a time. The /join 0 command
makes you PART all channels.
********************************************************************/
long IRCUserParse_Join(char *in, char ***channelarray, int *numchannels);

/********************************************************************
/PART channel
 
Leave channel. If no channel given then the channel is the current
ones..
********************************************************************/
long IRCUserParse_Part(char *in, char **newnickname);

/********************************************************************
/LEAVE channel
 
Leave channel. If no channel given then the channel is the current
ones..
********************************************************************/
long IRCUserParse_Leave(char *in, char **newnickname);

/********************************************************************
/QUIT reason
 
Causes you to disconnect from the server. If you
include a reason, it will be displayed on all channels
as you quit
********************************************************************/
long IRCUserParse_Quit(char *in, char **reason);

/********************************************************************
/NICK newnickname
 
Changes your online nick name. Alerts others to the
change of your nick
********************************************************************/
long IRCUserParse_Nick(char *in, char **newnickname);

/********************************************************************
/AWAY reason
 
Marks you as being away. A reason may also be supplied.
********************************************************************/
long IRCUserParse_Away(char *in, char **reason);

/********************************************************************
/WHOIS nick
 
Displays information of user requested. Includes Full
Name, Host, Channels User is in, and Oper Status
********************************************************************/
long IRCUserParse_Whois(char *in, char **nick);

/********************************************************************
/INVITE nick channel
 
Invite to a restricted channel
********************************************************************/
long IRCUserParse_Invite(char *in, char **nick, char **channel);

/********************************************************************
/KICK channel nick
 
Expulse user from channel
********************************************************************/
long IRCUserParse_Kick(char *in, char **channel, char **nick);

/********************************************************************
/TOPIC channel topic
 
Topic <channel> will display the current topic of
the given channel. Topic <channel> <topic>
will change the topic of the given channel.
********************************************************************/
long IRCUserParse_Topic(char *in, char **channel, char **topic);

/********************************************************************
/ME
 
My nick name whith a message
********************************************************************/
long IRCUserParse_Me(char *in, char **msg);

/********************************************************************
/MSG nick/channel msg
 
Send private message
********************************************************************/
long IRCUserParse_Msg(char *in, char **nickchannel, char **msg);

/********************************************************************
/PRIV nick/channel msg
 
Send private message
********************************************************************/
long IRCUserParse_Priv(char *in, char **nickchannel, char **msg);

/********************************************************************
/QUERY nick/channel msg
 
Direct Client To Client Protocol
********************************************************************/
long IRCUserParse_Query(char *in, char **nickchannel, char **msg);

/********************************************************************
/NOTICE nick/channel msg
 
Send a private message without open any new window. Like a blow in
the wind.
********************************************************************/
long IRCUserParse_Notice(char *in, char **nickchannel, char **msg);

/********************************************************************
/NOTIFY nick1 nick2, ...
 
Add to notify list. If it is activate show when a user enter or leave
a channel. 
********************************************************************/
long IRCUserParse_Notify(char *in, char ***nickarray, int *numnicks);

/********************************************************************
/IGNORE nickuserhost1 nickuserhost2, ...
 
Add to notify list. If it is activate show when a user enter or leave
a channel. 
********************************************************************/
long IRCUserParse_Ignore(char *in, char ***nickuserhostarray, int *numnickuserhosts);

/********************************************************************
/PING user
 
Sends a PING request to a user. Used for checking
connection and lag. Servers issue pings on a timed
basis to determine if users are still connected.
********************************************************************/
long IRCUserParse_Ping(char *in, char **user);

/********************************************************************
/WHO mask
 
Who allows you to search for users. Masks include:
nickname, #channel, hostmask (*.attbi.com)
********************************************************************/
long IRCUserParse_Who(char *in, char **mask);

/********************************************************************
/WHOWAS nick maxreplies
 
Displays information on a nick that has logged off. The
<max replies> field is optional, and limits how
many records will be returned.
********************************************************************/
long IRCUserParse_WhoWas( char *in, char **nick, int *maxreplies);

/********************************************************************
/ISON nick1 nick2 nick3 ...
 
Allows you to check the online status of a user, or a
list of users. Simple return, best used for scripts
********************************************************************/
long IRCUserParse_Ison( char *in, char ***nickarray, int *numnicks);

/********************************************************************
/CYCLE channel1 channel2, ...
 
Cycles the given channel(s). This command is equivalent
to sending a PART then a JOIN command.
********************************************************************/
long IRCUserParse_Cycle( char *in, char ***channelarray, int *numchannels);

/********************************************************************
/MOTD server
 
Displays the servers motd. Adding a server name allows
you to view motd’s on other servers.
********************************************************************/
long IRCUserParse_Motd( char *in, char **server);

/********************************************************************
/RULES server
 
Displays the ircd.rules of a server. Adding a server
name allows you to view rules on other servers
********************************************************************/
long IRCUserParse_Rules( char *in, char **server);

/********************************************************************
/LUSERS server
 
Displays current & max user loads, both global and
local. Adding a server name   allows you to view the
statistics from other servers.
********************************************************************/
long IRCUserParse_Lusers( char *in, char **server);

/********************************************************************
/VERSION server
 
Shows you the version of the IRCd and other
info related to it. If you specify a server, you
will be shown information relating to that server
********************************************************************/
long IRCUserParse_Version( char *in, char **server);

/********************************************************************
/ADMIN server
 
Displays the admin info of a server. If a server name
is included it will display the info of that server.
********************************************************************/
long IRCUserParse_Admin( char *in, char **server);

/********************************************************************
/USERHOST nick
 
Displays the userhost of the nick given. Generally used
for scripts
********************************************************************/
long IRCUserParse_Userhost( char *in, char **nick);

/********************************************************************
/KNOCK channel message
 
Allows you to ‘knock’ on an invite only
channel and ask for access. Will not work if channel
has one of the following modes set: +K +V. Will also
not work if you are banned
********************************************************************/
long IRCUserParse_Knock( char *in, char **channelmessage);

/********************************************************************
/VHOST login password
 
Hides your host name by using a vhost provided by the
server.
********************************************************************/
long IRCUserParse_Vhost( char *in, char **login, char **password);

/********************************************************************
/MODE chan/nick mode
 
Lets you set channel and user modes. See User &
Channel Modes for a list.
********************************************************************/
long IRCUserParse_Mode( char *in, char **nickchannel, char **mode);

/********************************************************************
/TIME server
 
Displays the servers date and time. Including a server
name allows you to check other servers.
********************************************************************/
long IRCUserParse_Time( char *in, char **server);

/********************************************************************
/BOTMOTD server
 
Displays the servers bot message of the day. Including
a server name allows you to check other servers
********************************************************************/
long IRCUserParse_BotMotd( char *in, char **server);

/********************************************************************
/IDENTIFY password
 
Sends your password to the services system to identify
to your nick.
********************************************************************/
long IRCUserParse_Identify( char *in, char **password);

/********************************************************************
/DNS option
 
Returns information about the IRC server's DNS cache.
Note, since most clients have a built-in DNS command,
you will most likely need to use /raw DNS to use this.
Opers may specify an l as the first parameter to the
command  to receive a list of entries in the DNS cache.
********************************************************************/
long IRCUserParse_Dns( char *in, char **option);

/********************************************************************
/USERIP nick
 
Returns the IP address of the user in question. This will be
shown encrypted.
********************************************************************/
long IRCUserParse_UserIp( char *in, char **nick);

/********************************************************************
/STATS option
 
Not all of the following STATS options are available to regular users
 
 B - banversion - Send the ban version list
 b - badword - Send the badwords list
 C - link - Send the link block list
 d - denylinkauto - Send the deny link (auto) block list
 D - denylinkall - Send the deny link (all) block list
 e - exceptthrottle - Send the except throttle block list
 E - exceptban - Send the except ban and except tkl block list
 f - spamfilter - Send the spamfilter list
 F - denydcc - Send the deny dcc block list
 G - gline - Send the gline and gzline list
   Extended flags: [+/-mrs] [mask] [reason] [setby]
     m Return glines matching/not matching the specified mask
     r Return glines matching/not matching the specified reason
     s Return glines set by/not set by clients matching the specified name
 I - allow - Send the allow block list
 j - officialchans - Send the offical channels list
 K - kline - Send the ban user/ban ip/except ban block list
 l - linkinfo - Send link information
 L - linkinfoall - Send all link information
 M - command - Send list of how many times each command was used
 n - banrealname - Send the ban realname block list
 O - oper - Send the oper block list
 P - port - Send information about ports
 q - sqline - Send the SQLINE list
 Q - bannick - Send the ban nick block list
 r - chanrestrict - Send the channel deny/allow block list
 R - usage - Send usage information
 S - set - Send the set block list
 s - shun - Send the shun list
   Extended flags: [+/-mrs] [mask] [reason] [setby]
     m Return shuns matching/not matching the specified mask
     r Return shuns matching/not matching the specified reason
     s Return shuns set by/not set by clients matching the specified name
 t - tld - Send the tld block list
 T - traffic - Send traffic information
 u - uptime - Send the server uptime and connection count
 U - uline - Send the ulines block list
 v - denyver - Send the deny version block list
 V - vhost - Send the vhost block list
 X - notlink - Send the list of servers that are not current linked
 Y - class - Send the class block list
 z - zip - Send compression information about ziplinked servers
 Z - mem - Send memory usage information
 
********************************************************************/
long IRCUserParse_Stats( char *in, char **option);

/********************************************************************
/CTCP
 
Client To Client Protocol
********************************************************************/
long IRCUserParse_CTCP( char *in, char **msg);

/********************************************************************
/DCC 
 
Direct Client To Client Protocol
********************************************************************/
long IRCUserParse_DCC( char *in, char **msg);

/********************************************************************
/MAP
 
Displays a network map
********************************************************************/

/********************************************************************
/LINKS
 
Displays a list of all servers linked to the network
********************************************************************/

/********************************************************************
/SETNAME
 
Allows users to change their ‘Real Name’
without reconnecting
********************************************************************/

/********************************************************************
/LICENSE
 
Displays the GNU License
********************************************************************/

/********************************************************************
/MODULE
 
Lists all loaded modules
********************************************************************/

/********************************************************************
/PARTALL
 
Leave all channels
********************************************************************/

/********************************************************************
/CHAT
 
Open DCC chat
********************************************************************/
long IRCUserParse_Chat( char *in, char **msg);

#endif

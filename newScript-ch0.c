
#include "cJSON.h"

const char* firstRunDialogues[] = {
	"{\"text\": \"This game is not suitable for children or those who are easily disturbed.\", \"character\": \" \", \"sprite\": \" \"}",
	"{\"text\": \"Individuals suffering from anxiety or depression may not have a safe experience playing this game. For content warnings, please visit: https://ddlc.moe/warning.html\", \"character\": \" \", \"sprite\": \" \"}",
	"{\"text\": \"By playing Doki Doki Literature Club. you agree that you are at least 13 years of age, and you consent to your exposure of highly disturbing content.\", \"character\": \" \", \"sprite\": \" \"}",
};


const char* dialogues[] = {

	"{\"music\": \"audio/bgm/2.ogg\"}", // This entire thing fails if one entry is wrong // OH GOD IT WORKS.

	"{\"text\":\"REMOVE MONIKA - 2/3 of her is gone\", \"character\" : \"Monika\", \"sprite\" : \"NULLER\"}",
	"{\"text\":\"REMOVE YURI\", \"character\" : \"Yuri\", \"sprite\" : \"NULLER\"}",
	"{\"text\":\"REMOVE NATSUKI\", \"character\" : \"Natsuki\", \"sprite\" : \"NULLER\"}",

	"{\"text\":\"REMOVE SAYORI\", \"character\" : \"Sayori\", \"sprite\" : \"NULLER\"}",


	"{\"text\":\"Heeeeeeeyyy!!\", \"character\" : \"Sayori\", \"sprite\" : \"sayori4p\"}",
	"{\"text\":\"I see an annoying girl running toward me from the distance, waving her arms in the air like she's totally oblivious to any attention she might draw to herself.\", \"character\" : \" \", \"sprite\" : \" \"};"
	"{\"text\":\"That girl is Sayori, my neighbor and good friend since we were children.\", \"character\" : \" \", \"sprite\" : \" \"}",

	"{\"text\":\"You know, the kind of friend you'd never see yourself making today, but it just kind of works out because you've known each other for so long?\", \"character\" : \" \", \"sprite\" : \" \"}"

	"{\"text\":\"We used to walk to school together on days like this, but starting around high school she would oversleep more and more frequently, and I would get tired of waiting up.\", \"character\" : \" \", \"sprite\": \" \"}",
	"{\"text\":\"But if she's going to chase after me like this, I almost feel better off running away.\", \"character\" : \" \", \"sprite\": \" \"}",
	"{\"text\":\"However, I just sigh and idle in front of the crosswalk and let Sayori catch up to me.\", \"character\" : \" \", \"sprite\": \" \"}",

	"{\"text\":\"Haaahhh...haaahhh...\", \"character\" : \"Sayori\", \"sprite\": \"sayori4p\"}",


	"{\"text\":\"Heeeeeeeyyy!!\", \"character\" : \"Sayori\", \"sprite\": \"sayori4p\"}",
	"{\"text\":\"Heeeeeeeyyy!!\", \"character\" : \"Sayori\", \"sprite\": \"sayori4p\"}",
	"{\"text\":\"Heeeeeeeyyy!!\", \"character\" : \"Sayori\", \"sprite\": \"sayori4p\"}",
	"{\"text\":\"Heeeeeeeyyy!!\", \"character\" : \"Sayori\", \"sprite\": \"sayori4p\"}",

	"{\"text\": \"I overslept again!\", \"character\": \"Sayori\", \"sprite\": \" \"}",
	"{\"text\": \"But I caught you this time!\", \"character\": \"Sayori\", \"sprite\": \" \"}",
	"{\"text\": \"Maybe, but only because I decided to stop and wait for you.\", \"character\": \"MC\", \"sprite\": \" \"}",
	"{\"text\": \"Eeehhhhh, you say that like you were thinking about ignoring me!\", \"character\": \"Sayori\", \"sprite\": \"sayori5c\"}",
	"{\"text\": \"That's mean, [player]!\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Well, if people stare at you for acting weird then I don't want them to think we're a couple or something.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Fine, fine.\", \"character\": \"Sayori\", \"sprite\": \"sayori1a\"}",
	"{\"text\": \"But you did wait for me, after all.\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"I guess you don't have it in you to be mean even if you want to~\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Whatever you say, Sayori...\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Ehehe~\", \"character\": \"Sayori\", \"sprite\": \"sayori1q\"}",
	"{\"text\": \"We cross the street together and make our way to school.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"As we draw near, the streets become increasingly speckled with other students making their daily commute.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"By the way, [player]...\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Have you decided on a club to join yet?\", \"character\": \"Sayori\", \"sprite\": \"\"}"

	"{\"text\": \"A club?\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"I told you already, I'm really not interested in joining any clubs.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"I haven't been looking, either.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Eh? That's not true!\", \"character\": \"Sayori\", \"sprite\": \"sayori4h\"}",
	"{\"text\": \"You told me you would join a club this year!\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Did I...?\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"I'm sure it's possible that I did, in one of our many conversations where I dismissively go along with whatever she's going on about.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Sayori likes to worry a little too much about me, when I'm perfectly content just getting by on the average while spending my free time on games and anime.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Uh-huh!\", \"character\": \"Sayori\", \"sprite\": \"sayori4j\"}",
	"{\"text\": \"I was talking about how I'm worried that you won't learn how to socialize or have any skills before college.\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Your happiness is really important to me, you know!\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"And I know you're happy now, but I'd die at the thought of you becoming a NEET in a few years because you're not used to the real world!\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"You trust me, right?\", \"character\": \"Sayori\", \"sprite\": \"sayori4g\"}",
	"{\"text\": \"Don't make me keep worrying about you...\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Alright, alright...\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"I'll look at a few clubs if it makes you happy.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"No promises, though.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Will you at least promise me you'll try a little?\", \"character\": \"Sayori\", \"sprite\": \"sayori1h\"}",
	"{\"text\": \"Yeah, I guess I'll promise you that.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Yaay~!\", \"character\": \"Sayori\", \"sprite\": \"sayori4r\"}",
	"{\"text\": \"Why do I let myself get lectured by such a carefree girl?\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"More than that, I'm surprised I even let myself relent to her.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"I guess seeing her worry so much about me makes me want to ease her mind at least a little bit - even if she does exaggerate everything inside of her head.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"The school day is as ordinary as ever, and it's over before I know it.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"After I pack up my things, I stare blankly at the wall, looking for an ounce of motivation.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Clubs...\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Sayori wants me to check out some clubs.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"I guess I have no choice but to start with the anime club...\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Hellooo?\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"Sayori...?\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Sayori must have come into the classroom while I was spacing out.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"I look around and realize that I'm the only one left in the classroom.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"I thought I'd catch you coming out of the classroom, but I saw you just sitting here and spacing out, so I came in.\", \"character\": \"Sayori\", \"sprite\": \"sayori1a\"}",
	"{\"text\": \"Honestly, you're even worse than me sometimes... I'm impressed!\", \"character\": \"Sayori\", \"sprite\": \"\"}",
	"{\"text\": \"You don't need to wait up for me if it's going to make you late to your own club.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Well, I thought you might need some encouragement, so I thought, you know...\", \"character\": \"Sayori\", \"sprite\": \"sayori1y\"}",
	"{\"text\": \"Know what?\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Well, that you could come to my club!\", \"character\": \"Sayori\", \"sprite\": \"sayori1a\"}",
	"{\"text\": \"Sayori...\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Yeah??\", \"character\": \"Sayori\", \"sprite\": \"sayori4r\"}",
	"{\"text\": \"...There is no way I'm going to your club.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"Eeeehhhhh?! Meanie!\", \"character\": \"Sayori\", \"sprite\": \"sayori5d\"}",
	"{\"text\": \"Sayori is vice president of the Literature Club.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Not that I was ever aware that she had any interest in literature.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"In fact, I'm 99%% sure she only did it because she thought it would be fun to help start a new club.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Since she was the first one to show interest after the one who proposed the club, she inherited the title \\\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"That said, my interest in literature is guaranteed to be even less.\", \"character\": \" \", \"sprite\": \"\"}",
	"{\"text\": \"Yeah. I'm going to the anime club.\", \"character\": \"MC\", \"sprite\": \"\"}",
	"{\"text\": \"C'mon, please?\", \"character\": \"Sayori\", \"sprite\": \"sayori1g\"}",
	"{\"text\": \"Why do you care so much, anyway?\", \"character\": \"MC\", \"sprite\": \"\"}",


};


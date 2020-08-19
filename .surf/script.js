/* based on chromium plugin code, adapted by Nibble<.gs@gmail.com> */
var hint_num_str = '';
var hint_elems = [];
var hint_open_in_new_tab = false;
var hint_enabled = false;

function hintMode(newtab){
	hint_enabled = true;
	if (newtab) {
		hint_open_in_new_tab = true;
	} else {
		hint_open_in_new_tab = false;
	}
	setHints();
	document.removeEventListener('keydown', initKeyBind, false);
	document.addEventListener('keydown', hintHandler, false);
	hint_num_str = '';
}

function hintHandler(e){
	e.preventDefault();  //Stop Default Event
	var pressedKey = e.key;
	if (pressedKey == 'Enter') {
		if (hint_num_str == '')
			hint_num_str = '1';
		judgeHintNum(Number(hint_num_str));
	} else if (/[0-9]/.test(pressedKey)) {
		hint_num_str += pressedKey;
		var hint_num = Number(hint_num_str);
		if (hint_num * 10 > hint_elems.length + 1)
			judgeHintNum(hint_num);
	}
}

function setHighlight(elem, is_active) {
	if (is_active) {
		var active_elem = document.body.querySelector('a[highlight=hint_active]');
		if (active_elem != undefined)
			active_elem.setAttribute('highlight', 'hint_elem');
		elem.setAttribute('highlight', 'hint_active');
	} else {
		elem.setAttribute('highlight', 'hint_elem');
	}

}

function setHintRules() {
	if (document.styleSheets.length < 1) {
		var style = document.createElement("style");
		style.appendChild(document.createTextNode(""));
		document.head.appendChild(style);
	}
	var ss = document.styleSheets[0];
	ss.insertRule('a[highlight=hint_elem] {background-color: #005050}', 0);
	ss.insertRule('a[highlight=hint_active] {background-color: lime}', 0);
}

function deleteHintRules() {
	var ss = document.styleSheets[0];
	ss.deleteRule(0);
	ss.deleteRule(0);
}

function judgeHintNum(hint_num) {
	var hint_elem = hint_elems[hint_num - 1];
	if (hint_elem != undefined) {
		execSelect(hint_elem);
	} else {
		removeHints();
	}
}

function execSelect(elem) {
	var tag_name = elem.tagName.toLowerCase();
	var type = elem.type ? elem.type.toLowerCase() : "";
	if (tag_name == 'a' && elem.href != '') {
		setHighlight(elem, true);
		// TODO: ajax, <select>
		if (hint_open_in_new_tab)
			window.open(elem.href);
		else location.href=elem.href;

	} else if (tag_name == 'input' && (type == "submit" || type == "button" || type == "reset")) {
		elem.click();
	} else if (tag_name == 'input' && (type == "radio" || type == "checkbox")) {
		// TODO: toggle checkbox
		elem.checked = !elem.checked;
	} else if (tag_name == 'input' || tag_name == 'textarea') {
		elem.focus();
		elem.setSelectionRange(elem.value.length, elem.value.length);
	}
	removeHints();
}

function setHints() {
	setHintRules();
	var win_top = window.scrollY;
	var win_bottom = win_top + window.innerHeight;
	var win_left = window.scrollX;
	var win_right = win_left + window.innerWidth;
	// TODO: <area>
	var elems = document.body.querySelectorAll('a, input:not([type=hidden]), textarea, select, button');
	var div = document.createElement('div');
	div.setAttribute('highlight', 'hints');
	document.body.appendChild(div);
	for (var i = 0; i < elems.length; i++) {
		var elem = elems[i];
		if (!isHintDisplay(elem))
			continue;
		var pos = elem.getBoundingClientRect();
		var elem_top = win_top + pos.top;
		var elem_bottom = win_top + pos.bottom;
		var elem_left = win_left + pos.left;
		var elem_right = win_left + pos.left;
		if ( elem_bottom >= win_top && elem_top <= win_bottom) {
			hint_elems.push(elem);
			setHighlight(elem, false);
			var span = document.createElement('span');
			span.style.cssText = [
				'left: ', elem_left, 'px;',
				'top: ', elem_top, 'px;',
				'position: absolute;',
				'font-size: 9px;',
				'background-color: ' + (hint_open_in_new_tab ? '#ff8800' : '#ff8800') + ';',
				'color: black;',
				'font-weight: bold;',
				'padding: 0px 1px;',
				'z-index: 100000;'
			].join('');
			span.innerHTML = hint_elems.length;
			div.appendChild(span);
			if (elem.tagName.toLowerCase() == 'a') {
				if (hint_elems.length == 1) {
					setHighlight(elem, true);
				} else {
					setHighlight(elem, false);
				}
			}
		}
	}
}

function isHintDisplay(elem) {
	var pos = elem.getBoundingClientRect();
	return (pos.height != 0 && pos.width != 0);
}

function removeHints() {
	if (!hint_enabled)
		return;
	hint_enabled = false;
	deleteHintRules();
	for (var i = 0; i < hint_elems.length; i++) {
		hint_elems[i].removeAttribute('highlight');
	}
	hint_elems = [];
	hint_num_str = '';
	var div = document.body.querySelector('div[highlight=hints]');
	if (div != undefined) {
		document.body.removeChild(div);
	}
	document.removeEventListener('keydown', hintHandler, false);
	document.addEventListener('keydown', initKeyBind, false);
}

function addKeyBind( key, func, eve ){
	var pressedKey = eve.key;
	if( pressedKey == key ){
		eve.preventDefault();  //Stop Default Event
		eval(func);
	}
}

document.addEventListener( 'keydown', initKeyBind, false );

function initKeyBind(e){
	var t = e.target;
	if( t.nodeType == 1){
		addKeyBind( 'f', 'hintMode()', e );
		addKeyBind( 'F', 'hintMode(true)', e );
		addKeyBind( 'q', 'removeHints()', e );
	}
}

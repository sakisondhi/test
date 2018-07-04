import {html, PolymerElement} from '@polymer/polymer/polymer-element.js';
/**
 * `map-comp`
 * shows the map and location pointer of the position given and to show accuracy by representing with circle
 *
 * @customElement
 * @polymer
 * @demo demo/index.html
 */
class MapComp extends PolymerElement {
  constructor()
  {
    super(); // page become more responsive to scroll
  }
  connectedCallback() {                //add listener
    super.connectedCallback();
    window.addEventListener('touchmove', event => {
      console.log(event);
    },{passive: true});
  }

  disconnectedCallback() {            //remove listener prevent memory leak
    super.disconnectedCallback();
    window.removeEventListener('touchmove', event => {
      console.log(event);
    },{passive: true});
  }
  ready()
  {
    super.ready();
    var elt=document.createElement('script');
    elt.type = 'text/javascript';
    window.initGoogleMapApi = this.initGoogleMap.bind(this);
    elt.src='https://maps.googleapis.com/maps/api/js?key=AIzaSyCF9soBfM0LVmScVCkknTyqL7GAOF7g3D0&callback=initGoogleMapApi';
    this.$.tag.appendChild(elt);
  }

  initGoogleMap()
  {
    var latlong={lat:this.latitude,lng:this.longitude };
    var acc=this.accuracy;
    // set properties of map
    var mapOptions={
      zoom:15,
      mapTypeId: 'terrain', //'satellite';
      center: latlong//or new google.maps.LatLng(28.455134,77.071841)

    }
    //creates the map
    var map= new google.maps.Map(this.$.mapcanvas,mapOptions); //??????????????

    // set the marker
    var marker = new google.maps.Marker({
        position: latlong,
        map:map,
        title:'hello'
    });

    // draw a circle to tell the accuracy that we can be anywhere in this circle
    var circle = new google.maps.Circle({
           strokeColor: '#0000FF',
           strokeOpacity: 0.8,
           strokeWeight: 2,
           fillColor: '#0000FF',
           fillOpacity: 0.2,
           map: map,
           center: latlong,
           radius: acc,
    });
  }

  static get template()
  {
    return html`
      <style>
        :host {
          display: block;
        }
      </style>
      <div id="tag">
       <div style="height:650px; width:100%;" id="mapcanvas"></div>
      </div>
    `;
  }

  static get properties() {

    return {
      longitude: {
        type: Number
      },
      latitude: {
        type: Number
      },
      accuracy: {
        type: Number
      }
    };

  }

}

window.customElements.define('map-comp', MapComp);
